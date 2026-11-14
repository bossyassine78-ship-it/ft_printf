#include "libftprintf.h"

int    ft_puthexU(long nb)
{
    char *base;
    int count;
    
    count = 0;
    base = "0123456789ABCDEF";
    if (nb >= 16)
        count += ft_puthexU(nb / 16);
    ft_putchar(base[nb % 16]);
    return (count + 1);
}