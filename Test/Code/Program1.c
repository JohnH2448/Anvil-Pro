int main(void) {
    unsigned a = 1;
    unsigned b = 3;
    unsigned c = 5;
    unsigned d = 7;
    unsigned e = 9;
    unsigned f = 11;
    unsigned g = 13;
    unsigned h = 15;
    unsigned i;

    for (i = 0; i < 24; i++) {
        if ((a ^ c) & 1u) {
            b = b + a + d;
            e = e ^ b;
        } else {
            b = b + c - d;
            e = e + 7u;
        }

        if (b < 40u) {
            f = f + b;
        } else if (b < 90u) {
            f = f ^ (b << 1);
        } else {
            f = f - (b >> 1);
        }

        if (f & 1u) {
            g = g + f + i;
        } else {
            g = g ^ (f + i);
        }

        h = h + g - e;
        a = a + 3u;
        c = c ^ h;
        d = d + 5u;

        if (d > 60u) {
            d = d - 41u;
        }
    }

    if (a == 73u &&
        b == 4294967229u &&
        c == 4294966977u &&
        d == 48u &&
        e == 4294967277u &&
        f == 4294967049u &&
        g == 4294966321u &&
        h == 4294962984u) {
        asm volatile ("addi x10, x0, 101");
    } else {
        asm volatile ("addi x10, x0, 258");
    }

    while (1) {
    }

    return 0;
}

