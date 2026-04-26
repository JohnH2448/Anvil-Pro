#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <reent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "platform.h"

#undef errno
extern int errno;

extern unsigned char __heap_start;
extern unsigned char __heap_end;

static unsigned char *heap_cursor;

int _write(int file, const char *ptr, int len)
{
    (void)file;

    if (len < 0) {
        errno = EINVAL;
        return -1;
    }

    for (int i = 0; i < len; ++i) {
        anvil_putc(ptr[i]);
    }

    return len;
}

_ssize_t _write_r(struct _reent *reent, int file, const void *ptr, size_t len)
{
    (void)reent;
    return (_ssize_t)_write(file, (const char *)ptr, (int)len);
}

void *_sbrk(ptrdiff_t incr)
{
    unsigned char *previous = heap_cursor;
    unsigned char *next = heap_cursor + incr;

    if (heap_cursor == NULL) {
        heap_cursor = &__heap_start;
        previous = heap_cursor;
        next = heap_cursor + incr;
    }

    if (next < &__heap_start || next > &__heap_end) {
        errno = ENOMEM;
        return (void *)-1;
    }

    heap_cursor = next;
    return previous;
}

void *_sbrk_r(struct _reent *reent, ptrdiff_t incr)
{
    void *result = _sbrk(incr);

    if (result == (void *)-1 && reent != NULL) {
        reent->_errno = errno;
    }

    return result;
}

void _exit(int status)
{
    register uint32_t a0 asm("a0") = status == 0 ? ANVIL_TOHOST_PASS : ANVIL_TOHOST_FAIL;
    asm volatile ("" : "+r"(a0));
    for (;;) {
        asm volatile ("nop");
    }
}

int _close(int file)
{
    (void)file;
    errno = EBADF;
    return -1;
}

int _close_r(struct _reent *reent, int file)
{
    int result = _close(file);

    if (result < 0 && reent != NULL) {
        reent->_errno = errno;
    }

    return result;
}

int _fstat(int file, struct stat *st)
{
    (void)file;
    st->st_mode = S_IFCHR;
    return 0;
}

int _fstat_r(struct _reent *reent, int file, struct stat *st)
{
    int result = _fstat(file, st);

    if (result < 0 && reent != NULL) {
        reent->_errno = errno;
    }

    return result;
}

int _isatty(int file)
{
    (void)file;
    return 1;
}

int _isatty_r(struct _reent *reent, int file)
{
    (void)reent;
    return _isatty(file);
}

int _lseek(int file, int ptr, int dir)
{
    (void)file;
    (void)ptr;
    (void)dir;
    return 0;
}

_off_t _lseek_r(struct _reent *reent, int file, _off_t ptr, int dir)
{
    (void)reent;
    return (_off_t)_lseek(file, (int)ptr, dir);
}

int _read(int file, char *ptr, int len)
{
    (void)file;
    (void)ptr;
    (void)len;
    return 0;
}

_ssize_t _read_r(struct _reent *reent, int file, void *ptr, size_t len)
{
    (void)reent;
    return (_ssize_t)_read(file, (char *)ptr, (int)len);
}

int _kill(int pid, int sig)
{
    (void)pid;
    (void)sig;
    errno = EINVAL;
    return -1;
}

int _kill_r(struct _reent *reent, int pid, int sig)
{
    int result = _kill(pid, sig);

    if (result < 0 && reent != NULL) {
        reent->_errno = errno;
    }

    return result;
}

int _getpid(void)
{
    return 1;
}

int _getpid_r(struct _reent *reent)
{
    (void)reent;
    return _getpid();
}
