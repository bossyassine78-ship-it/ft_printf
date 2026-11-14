#include "libftprintf.h"

int    ft_puthex(unsigned long nb)
{
    char *base;
    int count;
    
    count = 0;
    base = "0123456789abcdef";
    if (nb >= 16)
        count += ft_puthex(nb / 16);
    ft_putchar(base[nb % 16]);
    return (count + 1);
}