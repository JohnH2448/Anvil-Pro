#include <stdint.h>
#include <stdio.h>

static uint32_t register_storm(uint32_t seed, uint32_t rounds)
{
    uint32_t a = seed + 0x10203040u;
    uint32_t b = seed ^ 0x55667788u;
    uint32_t c = seed + 0x13579bdfu;
    uint32_t d = seed ^ 0x2468ace0u;
    uint32_t e = seed + 0x0f1e2d3cu;
    uint32_t f = seed ^ 0x4b5a6978u;
    uint32_t g = seed + 0x89abcdefu;
    uint32_t h = seed ^ 0xfedcba98u;

    for (uint32_t i = 0; i < rounds; ++i) {
        a += 0x11111111u;
        b ^= 0x01010101u;
        c += 0x33333333u;
        d ^= 0x70707070u;

        e += a >> 3;
        f ^= b << 5;
        g += c >> 7;
        h ^= d << 2;

        a ^= e + i;
        b += f ^ (i << 1);
        c ^= g + (i << 2);
        d += h ^ (i << 3);

        e ^= a >> 11;
        f += b << 1;
        g ^= c >> 13;
        h += d << 3;

        a += g ^ 0x0000ffffu;
        b ^= h + 0xffff0000u;
        c += e ^ 0x00ff00ffu;
        d ^= f + 0xff00ff00u;
    }

    return a ^ b ^ c ^ d ^ e ^ f ^ g ^ h;
}

static uint32_t dependency_light(uint32_t seed, uint32_t rounds)
{
    uint32_t a0 = seed + 3u;
    uint32_t a1 = seed + 5u;
    uint32_t a2 = seed + 7u;
    uint32_t a3 = seed + 11u;
    uint32_t a4 = seed + 13u;
    uint32_t a5 = seed + 17u;
    uint32_t a6 = seed + 19u;
    uint32_t a7 = seed + 23u;

    for (uint32_t i = 0; i < rounds; ++i) {
        a0 = (a0 << 3) ^ (a0 >> 5) ^ i;
        a1 = (a1 << 5) ^ (a1 >> 7) ^ (i + 1u);
        a2 = (a2 << 7) ^ (a2 >> 9) ^ (i + 2u);
        a3 = (a3 << 9) ^ (a3 >> 11) ^ (i + 3u);
        a4 = (a4 << 11) ^ (a4 >> 13) ^ (i + 4u);
        a5 = (a5 << 13) ^ (a5 >> 15) ^ (i + 5u);
        a6 = (a6 << 15) ^ (a6 >> 17) ^ (i + 6u);
        a7 = (a7 << 17) ^ (a7 >> 19) ^ (i + 7u);

        a0 += a4;
        a1 += a5;
        a2 += a6;
        a3 += a7;
        a4 ^= a0 >> 3;
        a5 ^= a1 >> 5;
        a6 ^= a2 >> 7;
        a7 ^= a3 >> 9;
    }

    return a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7;
}

static uint32_t branch_sparse(uint32_t seed, uint32_t rounds)
{
    uint32_t a = seed + 0x1001u;
    uint32_t b = seed + 0x2002u;
    uint32_t c = seed + 0x3003u;
    uint32_t d = seed + 0x4004u;

    for (uint32_t i = 0; i < rounds; ++i) {
        a += b ^ (i << 2);
        b ^= c + (i << 3);
        c += d ^ (i << 4);
        d ^= a + (i << 5);

        if ((i & 63u) == 0u) {
            a ^= d >> 1;
            c += b << 1;
        }
    }

    return a ^ b ^ c ^ d;
}

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("register math start\n");

    printf("storm begin\n");
    uint32_t r0 = register_storm(0x00000001u, 1600);
    uint32_t r1 = register_storm(0x00000055u, 1600);
    printf("storm done\n");

    printf("dependency light begin\n");
    uint32_t r2 = dependency_light(0x00000101u, 1800);
    uint32_t r3 = dependency_light(0x00000202u, 1800);
    printf("dependency light done\n");

    printf("branch sparse begin\n");
    uint32_t r4 = branch_sparse(0x00000303u, 2200);
    uint32_t r5 = branch_sparse(0x00000404u, 2200);
    printf("branch sparse done\n");

    volatile uint32_t result = r0 ^ r1 ^ r2 ^ r3 ^ r4 ^ r5;

    if (result == 0x4c0e7e79u) {
        printf("register math pass\n");
    } else {
        printf("register math fail\n");
    }

    printf("tohost");
    return 0;
}
