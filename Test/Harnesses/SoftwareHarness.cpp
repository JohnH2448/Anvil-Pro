#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

#include "VTop.h"
#include "verilated.h"

static constexpr uint64_t kMaxCycles = 10000000;
static constexpr uint32_t kDebugLogMask = 0x3ffu;

static void tick_full_cycle(VTop* top) {
    top->clock = 1;
    top->eval();

    top->clock = 0;
    top->eval();
}

static void apply_reset(VTop* top) {
    top->clock = 0;
    top->reset = 1;
    top->eval();
    tick_full_cycle(top);
    top->reset = 0;
    top->eval();
}

static uint8_t debug_log_byte(const VTop* top, uint32_t index) {
    const uint32_t offset = index & kDebugLogMask;
    const uint32_t word_index = offset >> 2;
    const uint32_t byte_shift = (offset & 0x3u) * 8u;

    return static_cast<uint8_t>((top->debugLogWindow[word_index] >> byte_shift) & 0xffu);
}

static bool flush_debug_log(const VTop* top, uint32_t& consumed_index, std::string& token_window) {
    const uint32_t produced_index = static_cast<uint32_t>(top->debugLogIndex);
    bool saw_tohost = false;

    while (consumed_index != produced_index) {
        const uint8_t byte = debug_log_byte(top, consumed_index);
        std::cout.put(static_cast<char>(byte));

        token_window.push_back(static_cast<char>(byte));
        if (token_window.size() > 6) {
            token_window.erase(0, token_window.size() - 6);
        }

        if (token_window == "tohost") {
            saw_tohost = true;
        }

        ++consumed_index;
    }

    std::cout.flush();
    return saw_tohost;
}

static void print_ipc(uint64_t retired_total, uint64_t cycle) {
    const double ipc = cycle == 0 ? 0.0 : static_cast<double>(retired_total) / static_cast<double>(cycle);

    std::cout
        << "Retired " << retired_total
        << " instructions in " << cycle
        << " cycles, IPC="
        << std::fixed << std::setprecision(4) << ipc
        << '\n';
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    uint64_t max_cycles = kMaxCycles;
    if (argc >= 2) {
        try {
            max_cycles = std::stoull(argv[1]);
        } catch (...) {
            std::cerr << "Invalid max cycle limit: " << argv[1] << '\n';
            return 2;
        }
    }

    auto* top = new VTop;
    uint64_t cycle = 0;
    uint32_t consumed_debug_index = 0;
    std::string token_window;
    bool tohost_armed = false;
    uint64_t retired_total = 0;

    apply_reset(top);

    while (!Verilated::gotFinish()) {
        ++cycle;
        tick_full_cycle(top);
        retired_total += static_cast<uint64_t>(top->retired & 0x3u);

        tohost_armed |= flush_debug_log(top, consumed_debug_index, token_window);
        if (tohost_armed) {
            std::cout
                << "\nStopped at cycle " << cycle
                << " after stdout tohost token\n";
            print_ipc(retired_total, cycle);
            delete top;
            return 0;
        }

        if (cycle >= max_cycles) {
            std::cout << "\nInfinite loop after " << cycle << " cycles\n";
            print_ipc(retired_total, cycle);
            delete top;
            return 1;
        }
    }

    delete top;
    return 0;
}
