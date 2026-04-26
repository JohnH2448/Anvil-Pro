#include <stdint.h>
#include <stdio.h>

int main(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("hello ginger");

    return 0;
}