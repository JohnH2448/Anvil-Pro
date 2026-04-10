#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "VTop.h"
#include "verilated.h"

static void tick_full_cycle(VTop* top) {
    top->clock = 1;
    top->eval();

    top->clock = 0;
    top->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    auto* top = new VTop;
    uint64_t cycle = 0;

    top->clock = 0;
    top->reset = 0;
    top->eval();

    std::cout << "__READY__" << '\n' << std::flush;

    std::string command;
    while (std::getline(std::cin, command)) {
        while (!command.empty() && std::isspace(static_cast<unsigned char>(command.back()))) {
            command.pop_back();
        }

        if (command == "reset") {
            top->clock = 0;
            top->reset = 1;
            top->eval();
            tick_full_cycle(top);
            top->reset = 0;
            top->eval();
            cycle = 0;
            std::cout << "__RESET_DONE__" << '\n' << std::flush;
            continue;
        }

        if (command == "step") {
            ++cycle;
            top->reset = 0;
            tick_full_cycle(top);
            std::cout
                << "__STEP_DONE__ "
                << cycle
                << " "
                << std::hex << std::setw(8) << std::setfill('0')
                << static_cast<uint32_t>(top->tohost)
                << std::dec << '\n'
                << std::flush;
            continue;
        }

        if (command == "quit") {
            break;
        }

        std::cout << "__ERROR__ unknown command" << '\n' << std::flush;
    }

    delete top;
    return 0;
}
