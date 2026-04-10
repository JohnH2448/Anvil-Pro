#include <cstdint>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "VTop.h"
#include "verilated.h"

static constexpr uint64_t kMaxCycles = 50000;

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

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    auto* top = new VTop;
    uint64_t cycle = 0;

    apply_reset(top);

    while (!Verilated::gotFinish()) {
        ++cycle;
        tick_full_cycle(top);

        const uint32_t tohost = static_cast<uint32_t>(top->tohost);
        if (tohost == 0x101u || tohost == 0x102u) {
            std::cout
                << "Stopped at cycle " << cycle
                << " with tohost = 0x"
                << std::hex << std::setw(8) << std::setfill('0') << tohost
                << std::dec << '\n';
            delete top;
            return 0;
        }

        if (cycle >= kMaxCycles) {
            std::cout << "Infinite loop after " << cycle << " cycles\n";
            delete top;
            return 1;
        }
    }

    delete top;
    return 0;
}
