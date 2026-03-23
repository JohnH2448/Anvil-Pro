#include <iostream>
#include <cstdint>
#include <termios.h>
#include <unistd.h>

#include "VTop.h"
#include "verilated.h"

struct TermRawMode {
    termios oldt{};
    bool active{false};

    void enable() {
        if (active) return;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        newt.c_cc[VMIN]  = 1;
        newt.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        active = true;
    }

    void disable() {
        if (!active) return;
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        active = false;
    }

    ~TermRawMode() { disable(); }
};

static void tick_full_cycle(VTop* top) {
    top->clock = 0;
    top->eval();

    top->clock = 1;
    top->eval();
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    auto* top = new VTop;

    top->clock = 0;
    top->reset = 0;

    top->eval();

    TermRawMode raw;
    raw.enable();

    std::cout <<
        "Keys:\n"
        "  n : next cycle\n"
        "  r : reset cycle\n"
        "  q : quit\n";

    while (!Verilated::gotFinish()) {
        char c = 0;
        if (read(STDIN_FILENO, &c, 1) != 1) continue;

        if (c == 'q') {
            break;
        }

        if (c == 'r') {
            top->reset = 1;
            top->eval();
            tick_full_cycle(top);
            top->reset = 0;
            top->eval();
            continue;
        }

        if (c == 'n') {
            top->reset = 0;
            top->eval();
            tick_full_cycle(top);
        }
    }

    delete top;
    return 0;
}
