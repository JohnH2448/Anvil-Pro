#include <stdint.h>
#include <stdio.h>

static int32_t ilp_math(void)
{
    int32_t a = 1;
    int32_t b = 2;
    int32_t c = 3;
    int32_t d = 4;

    int32_t s0 = 0;
    int32_t s1 = 0;
    int32_t s2 = 0;
    int32_t s3 = 0;

    for (int i = 0; i < 100; ++i) {
        int32_t x0 = a + i;
        int32_t x1 = b + i;
        int32_t x2 = c + i;
        int32_t x3 = d + i;

        int32_t r0 = x0 * 3 + 7;
        int32_t r1 = x1 * 5 + 11;
        int32_t r2 = x2 * 7 + 13;
        int32_t r3 = x3 * 9 + 17;

        s0 += r0;
        s1 += r1;
        s2 += r2;
        s3 += r3;

        a += 1;
        b += 2;
        c += 3;
        d += 4;
    }

    return s0 + s1 + s2 + s3;
}

static int32_t ilp_array(void)
{
    int32_t data[16];
    int32_t out[16];

    for (int i = 0; i < 16; ++i) {
        data[i] = i + 1;
        out[i] = 0;
    }

    int32_t sum0 = 0;
    int32_t sum1 = 0;
    int32_t sum2 = 0;
    int32_t sum3 = 0;

    for (int i = 0; i < 16; i += 4) {
        int32_t a0 = data[i + 0];
        int32_t a1 = data[i + 1];
        int32_t a2 = data[i + 2];
        int32_t a3 = data[i + 3];

        int32_t r0 = a0 * 2 + 1;
        int32_t r1 = a1 * 3 + 2;
        int32_t r2 = a2 * 4 + 3;
        int32_t r3 = a3 * 5 + 4;

        out[i + 0] = r0;
        out[i + 1] = r1;
        out[i + 2] = r2;
        out[i + 3] = r3;

        sum0 += r0;
        sum1 += r1;
        sum2 += r2;
        sum3 += r3;
    }

    return sum0 + sum1 + sum2 + sum3 + out[0] + out[5] + out[10] + out[15];
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    return 0;
}