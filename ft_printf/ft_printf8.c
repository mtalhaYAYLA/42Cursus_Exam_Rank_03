#include <unistd.h>
#include <stdarg.h>

void    ft_putstr(char *str, int *line)
{
    if(!str)
        str = "(null)";
    while(*str)
        *line += write(1, str++, 1);
}

void    ft_putnbr(long long int nbr, int base, int *len)
{
    char *nbrdizi = "0123456789abcdef";
    
    if(nbr < 0)
    {
        nbr *= -1;
        *len += write(1 ,"-", 1);
    }
    if(nbr >= base)
        ft_putnbr(nbr / base, base, len);
    *len += write(1, &nbrdizi[nbr % base], 1);
}

int ft_printf(const char *str, ... )
{
    int len = 0;
    va_list args;

    va_start(args, str);
    while(*str)
    {
        if(*str == '%' && (*(str + 1) == 's' || *(str + 1) == 'd' || *(str + 1) == 'x'))
        {
            str++;
            if(*str == 's')
                ft_putstr(va_arg(args, char *), &len);
            else if(*str == 'd')
                ft_putnbr((long long int)va_arg(args, int), 10, &len);
            else if(*str == 'x')
                ft_putnbr((long long int)va_arg(args, unsigned int), 16, &len);
        }
        else
            len += write(1, str, 1);
        str++;
    }
    va_end(args);
    return(len);
}