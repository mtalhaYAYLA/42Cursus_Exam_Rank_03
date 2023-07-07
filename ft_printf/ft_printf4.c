#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char* str, int *line)
{
    if(!str)                  // bunu iyice kavramalısın; çözüldü normal printf te (null) yazıyorda ondan :));
        str = "(null)";
    while(*str)
        *line += write(1, str++, 1);
}

void    ft_putnbr(long long int nbr, int base, int *line)
{
    char *nbrdizi = "0123456789abcdef";

    if(nbr < 0)
    {
        nbr *= -1;
        *line += write(1, "-", 1);
    }
    if(nbr >= base)
        ft_putnbr(nbr / base, base, line);
    *line += write(1, &nbrdizi[nbr % base], 1);
}

int ft_printf(const char *str, ... )
{
    int line = 0;
    va_list args;

    va_start(args, str);
    while(*str)
    {
        if(*str == '%' && (*(str + 1) == 's' || *(str + 1) == 'd' || *(str + 1) == 'x'))
        {
            str++;
            if(*str == 's')
                ft_putstr(va_arg(args, char *), &line);
            else if(*str == 'd')
                ft_putnbr((long long int)va_arg(args, int), 10, &line);
            else if(*str == 'x')
                ft_putnbr((long long int)va_arg(args, unsigned int), 16, &line);
        }
        else
            line += write(1, str, 1);
        str++;
    }
    va_end(args);
    return(line);
}

#include <stdio.h>
int main()
{
    // int i = 0, j = 0;
    // i = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
    // j = printf("Hexadecimal for %d is %x\n", 42, 42);
    // printf("%d\n%d", i, j);


    int i = 0, j = 0;
    char *s = 0;
    i = ft_printf("%s", s);
    j = printf("%s", s);
    printf("%d\n%d", i, j);
}