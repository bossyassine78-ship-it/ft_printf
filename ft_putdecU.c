#include "libftprintf.h"

size_t   ft_putdecU(unsigned long nb)
{
    char *base;
    int count ;

    base = "0123456789";
    count = 0;
    if (nb >= 10)
        count += ft_putdecU(nb / 10);
    ft_putchar(base[nb % 10]);
    return (count + 1);
}