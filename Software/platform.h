#ifndef ANVIL_PLATFORM_H
#define ANVIL_PLATFORM_H

#include <stdint.h>

#define ANVIL_CLINT_BASE       0x80000000u
#define ANVIL_MTIMECMP_LO      (*(volatile uint32_t *)(ANVIL_CLINT_BASE + 0x00u))
#define ANVIL_MTIMECMP_HI      (*(volatile uint32_t *)(ANVIL_CLINT_BASE + 0x04u))
#define ANVIL_MTIME_LO         (*(volatile uint32_t *)(ANVIL_CLINT_BASE + 0x08u))
#define ANVIL_MTIME_HI         (*(volatile uint32_t *)(ANVIL_CLINT_BASE + 0x0cu))

#define ANVIL_DEBUG_LOG_BASE   ((volatile uint8_t *)0x00007400u)
#define ANVIL_DEBUG_LOG_SIZE   0x00000400u
#define ANVIL_DEBUG_LOG_INDEX  (*(volatile uint32_t *)0x000073fcu)

#define ANVIL_TOHOST_PASS      0x00000101u
#define ANVIL_TOHOST_FAIL      0x00000102u

#define ANVIL_MSTATUS_MIE      0x00000008u
#define ANVIL_MSTATUS_MPIE     0x00000080u
#define ANVIL_MIE_MTIE         0x00000080u

extern volatile uint32_t anvil_timer_interrupt_count;
extern volatile uint32_t anvil_sync_trap_count;
extern volatile uint32_t anvil_last_trap_cause;
extern volatile uint32_t anvil_last_trap_epc;

static inline void anvil_putc(char c)
{
    uint32_t index = ANVIL_DEBUG_LOG_INDEX;
    ANVIL_DEBUG_LOG_BASE[index & (ANVIL_DEBUG_LOG_SIZE - 1u)] = (uint8_t)c;
    ANVIL_DEBUG_LOG_INDEX = index + 1u;
}

static inline void anvil_puts(const char *s)
{
    while (*s) {
        anvil_putc(*s++);
    }
}

static inline uint32_t anvil_read_mcycle(void)
{
    uint32_t value;
    asm volatile ("csrr %0, mcycle" : "=r"(value));
    return value;
}

static inline uint32_t anvil_read_minstret(void)
{
    uint32_t value;
    asm volatile ("csrr %0, minstret" : "=r"(value));
    return value;
}

static inline uint32_t anvil_read_mcause(void)
{
    uint32_t value;
    asm volatile ("csrr %0, mcause" : "=r"(value));
    return value;
}

static inline uint32_t anvil_read_mstatus(void)
{
    uint32_t value;
    asm volatile ("csrr %0, mstatus" : "=r"(value));
    return value;
}

static inline void anvil_write_mtvec(void (*handler)(void))
{
    asm volatile ("csrw mtvec, %0" :: "r"(handler));
}

static inline void anvil_enable_timer_interrupts(void)
{
    asm volatile ("csrs mie, %0" :: "r"(ANVIL_MIE_MTIE));
    asm volatile ("csrs mstatus, %0" :: "r"(ANVIL_MSTATUS_MIE));
}

static inline void anvil_disable_interrupts(void)
{
    asm volatile ("csrc mstatus, %0" :: "r"(ANVIL_MSTATUS_MIE));
}

static inline uint64_t anvil_read_mtime(void)
{
    uint32_t hi0;
    uint32_t lo;
    uint32_t hi1;

    do {
        hi0 = ANVIL_MTIME_HI;
        lo = ANVIL_MTIME_LO;
        hi1 = ANVIL_MTIME_HI;
    } while (hi0 != hi1);

    return ((uint64_t)hi1 << 32) | lo;
}

static inline void anvil_set_mtimecmp(uint64_t value)
{
    ANVIL_MTIMECMP_HI = 0xffffffffu;
    ANVIL_MTIMECMP_LO = (uint32_t)value;
    ANVIL_MTIMECMP_HI = (uint32_t)(value >> 32);
}

static inline uint32_t anvil_timer_interrupts_seen(void)
{
    return anvil_timer_interrupt_count;
}

static inline uint32_t anvil_sync_traps_seen(void)
{
    return anvil_sync_trap_count;
}

#endif
