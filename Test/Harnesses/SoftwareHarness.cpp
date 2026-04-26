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

static void flush_debug_log(const VTop* top, uint32_t& consumed_index) {
    const uint32_t produced_index = static_cast<uint32_t>(top->debugLogIndex);

    while (consumed_index != produced_index) {
        const uint8_t byte = debug_log_byte(top, consumed_index);
        std::cout.put(static_cast<char>(byte));
        ++consumed_index;
    }

    std::cout.flush();
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

    apply_reset(top);

    while (!Verilated::gotFinish()) {
        ++cycle;
        tick_full_cycle(top);
        flush_debug_log(top, consumed_debug_index);

        const uint32_t tohost = static_cast<uint32_t>(top->tohost);
        if (tohost == 0x101u || tohost == 0x102u) {
            std::cout
                << "\nStopped at cycle " << cycle
                << " with tohost = 0x"
                << std::hex << std::setw(8) << std::setfill('0') << tohost
                << std::dec << '\n';
            delete top;
            return tohost == 0x101u ? 0 : 1;
        }

        if (cycle >= max_cycles) {
            std::cout << "\nInfinite loop after " << cycle << " cycles\n";
            delete top;
            return 1;
        }
    }

    delete top;
    return 0;
}
