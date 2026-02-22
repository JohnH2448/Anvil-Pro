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
    top->redirect = 0;

    top->assert1 = 0;
    top->assert2 = 0;

    top->eval();

    TermRawMode raw;
    raw.enable();

    std::cout <<
        "Keys:\n"
        "  1 : assert1 and step\n"
        "  2 : assert1+assert2 and step\n"
        "  s : step (no asserts)\n"
        "  r : reset and step\n"
        "  d : redirect and step\n"
        "  q : quit\n";

    uint64_t cycle = 0;

    while (!Verilated::gotFinish()) {
        char c = 0;
        if (read(STDIN_FILENO, &c, 1) != 1) continue;

        bool pulse1 = false;
        bool pulse2 = false;
        bool do_step = false;
        bool do_reset = false;
        bool do_redir = false;

        switch (c) {
            case '1':
                pulse1 = true;
                pulse2 = false;
                do_step = true;
                break;

            case '2':
                pulse1 = true;
                pulse2 = true;
                do_step = true;
                break;

            case 's':
                do_step = true;
                break;

            case 'r':
                do_reset = true;
                do_step  = true;
                break;

            case 'd':
                do_redir = true;
                do_step  = true;
                break;

            case 'q':
                std::cout << "Quitting.\n";
                delete top;
                return 0;

            default:
                break;
        }

        if (!do_step) continue;

        top->reset = do_reset ? 1 : 0;
        top->redirect = do_redir ? 1 : 0;

        top->assert1 = pulse1 ? 1 : 0;
        top->assert2 = pulse2 ? 1 : 0;

        top->eval();

        tick_full_cycle(top);

        cycle++;
        std::cout << "\ncycle " << cycle << "\n";
        top->reset = 0;
        top->redirect = 0;
        top->assert1 = 0;
        top->assert2 = 0;
        top->eval();
    }

    delete top;
    return 0;
}