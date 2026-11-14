#include "libftprintf.h"

int   ft_putdec(long nb)
{
    char *base;
    int count ;

    base = "0123456789";
    count = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        count += 1;
        nb = -nb;
    }
    if (nb >= 10)
        count += ft_putdec(nb / 10);
    ft_putchar(base[nb % 10]);
    return (count + 1);
}