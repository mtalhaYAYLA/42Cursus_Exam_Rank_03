#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "./ft_printf9.c"  // ft_printf fonksiyonu burada tanımlı olduğu için burada include ediyoruz.

int main()
{
    int i= 0;
    int j = 0;

    i = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    j = printf("Hexadecimal for %d is %x\n", 42, 42);
    printf("\n%d\n%d", i, j);
}