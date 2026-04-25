#include "platform.h"

static unsigned int signature;
static unsigned int iterations;
static unsigned char scratch[128];

static void put_hex_nibble(unsigned int value)
{
    value &= 0xfu;
    anvil_putc((char)(value < 10u ? ('0' + value) : ('A' + value - 10u)));
}

static void put_hex32(unsigned int value)
{
    for (int shift = 28; shift >= 0; shift -= 4) {
        put_hex_nibble(value >> shift);
    }
}

static void put_byte_hex(unsigned int value)
{
    put_hex_nibble(value >> 4);
    put_hex_nibble(value);
}

static void put_hex_label(char a, char b, char c, unsigned int value)
{
    anvil_putc(a);
    anvil_putc(b);
    anvil_putc(c);
    anvil_putc('=');
    put_hex32(value);
    anvil_putc('\n');
}

static unsigned int mix(unsigned int value)
{
    value ^= value << 7;
    value ^= value >> 9;
    value += 0x45d9f3bu;
    value ^= value << 3;
    return value;
}

static void print_progress(unsigned int irq_count)
{
    anvil_putc('I');
    anvil_putc('R');
    anvil_putc('Q');
    anvil_putc('=');
    put_byte_hex(irq_count);
    anvil_putc(' ');
    anvil_putc('S');
    anvil_putc('=');
    put_hex32(signature);
    anvil_putc('\n');
}

static void initialize_scratch(void)
{
    for (unsigned int i = 0; i < 128u; ++i) {
        scratch[i] = (unsigned char)(i * 9u + 3u);
    }
}

static void stress_slice(void)
{
    unsigned int local[12];

    for (unsigned int i = 0; i < 12u; ++i) {
        unsigned int index = (iterations + i * 7u) & 127u;
        unsigned int value = scratch[index];
        local[i] = mix(signature ^ value ^ index ^ iterations);
        scratch[index] = (unsigned char)(local[i] + i);
    }

    for (unsigned int i = 0; i < 12u; ++i) {
        signature ^= local[i] + ((unsigned int)scratch[(iterations + i) & 127u] << (i & 7u));
        signature = mix(signature);
    }

    iterations += 1u;
}

int main(void)
{
    unsigned int last_irq_count = 0u;
    unsigned int guard = 0u;

    signature = 0x2468ace0u;
    initialize_scratch();

    anvil_set_mtimecmp(anvil_read_mtime() + 50u);
    anvil_enable_timer_interrupts();

    while (anvil_timer_interrupts_seen() < 8u && guard < 200000u) {
        unsigned int irq_count;

        stress_slice();
        irq_count = anvil_timer_interrupts_seen();

        if (irq_count != last_irq_count) {
            print_progress(irq_count);
            last_irq_count = irq_count;
        }

        guard += 1u;
    }

    anvil_disable_interrupts();

    put_hex_label('I', 'R', 'Q', anvil_timer_interrupts_seen());
    put_hex_label('I', 'T', 'R', iterations);
    put_hex_label('G', 'R', 'D', guard);
    put_hex_label('S', 'I', 'G', signature);

    anvil_putc('M');
    anvil_putc('C');
    anvil_putc('=');
    put_hex32(anvil_last_trap_cause);
    anvil_putc('\n');

    anvil_putc('M');
    anvil_putc('E');
    anvil_putc('=');
    put_hex32(anvil_last_trap_epc);
    anvil_putc('\n');

    anvil_putc('S');
    anvil_putc('T');
    anvil_putc('0');
    anvil_putc('=');
    for (unsigned int i = 0; i < 8u; ++i) {
        put_byte_hex(scratch[i]);
    }
    anvil_putc('\n');

    if (anvil_timer_interrupts_seen() < 8u) {
        return 1;
    }

    if (anvil_sync_traps_seen() != 0u) {
        return 1;
    }

    if (iterations == 0u || guard == 0u || signature == 0u) {
        return 1;
    }

    return 0;
}
