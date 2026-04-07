#include <iostream>
#include <cstdint>
#include <fcntl.h>
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
    top->clock = 1;
    top->eval();

    top->clock = 0;
    top->eval();
}

static void run_cycle(VTop* top, uint64_t cycle) {
    std::cout << "============ CYCLE " << cycle << " ============\n\n";
    top->reset = 0;
    top->eval();
    tick_full_cycle(top);
}

static void run_cycles_silent(VTop* top, uint64_t& cycle, int count) {
    const int saved_stdout = dup(STDOUT_FILENO);
    const int null_fd = open("/dev/null", O_WRONLY);

    if (saved_stdout >= 0 && null_fd >= 0) {
        dup2(null_fd, STDOUT_FILENO);
    }

    for (int i = 0; i < count; ++i) {
        cycle++;
        top->reset = 0;
        top->eval();
        tick_full_cycle(top);
    }

    if (saved_stdout >= 0 && null_fd >= 0) {
        fflush(stdout);
        dup2(saved_stdout, STDOUT_FILENO);
    }
    if (null_fd >= 0) close(null_fd);
    if (saved_stdout >= 0) close(saved_stdout);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    auto* top = new VTop;
    uint64_t cycle = 0;

    top->clock = 0;
    top->reset = 0;

    top->eval();

    TermRawMode raw;
    raw.enable();

    std::cout <<
        "Keys:\n"
        "  n : next cycle\n"
        "  h : next 100 cycles\n"
        "  r : reset cycle\n"
        "  q : quit\n";

    while (!Verilated::gotFinish()) {
        char c = 0;
        if (read(STDIN_FILENO, &c, 1) != 1) continue;

        if (c == 'q') {
            break;
        }

        if (c == 'r') {
            cycle = 0;
            std::cout << "========== CYCLE 0 =============\n\n";
            top->reset = 1;
            top->eval();
            tick_full_cycle(top);
            top->reset = 0;
            top->eval();
            continue;
        }

        if (c == 'n') {
            cycle++;
            run_cycle(top, cycle);
        }

        if (c == 'h') {
            run_cycles_silent(top, cycle, 99);
            cycle++;
            run_cycle(top, cycle);
        }
    }

    delete top;
    return 0;
}
