#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char* str, int *len)
{
    if(!str)
        str = "(null)";
    while(*str)
        *len += write(1, str++, 1);
}

void    ft_putnbr(long long int nbr, int base, int *len)
{
    char *numdizi = "0123456789abcdef";

    if(nbr < 0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if(nbr >= base)
        ft_putnbr((nbr / base), base, len);
    len += write(1, &numdizi[nbr % base], 1);

}

int	ft_printf(const char *str, ...)
{
    int len = 0;
    va_list argüman;

    va_start(argüman, str);

    while(*str)
    {
        if((*str == '%') && ((*(str + 1) == 's') || (*(str + 1) == 'd') || (*(str + 1) == 'x')))
        {
            str++;
            if(*str == 's')
                ft_putstr(va_arg(argüman, char *), &len);
            else if(*str == 'd')
                ft_putnbr((long long int)va_arg(argüman, int), 10, &len);
            else if(*str == 'x')
                ft_putnbr((long long int)va_arg(argüman, unsigned int), 16, &len);
        }
        else
            len += write(1, str, 1);
        str++;
    }
    va_end(argüman);
    return(len);
}

int main()
{
    ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}