#include "libftprintf.h"

int   ft_putdec(long nb)
{
    char *base;
    int count ;
    int check;

    base = "0123456789";
    count = 0;
    check = 0;
    if (nb < 0)
    {
        ft_putchar('-');
        count += 1;
        nb = -nb;
    }
    if (nb >= 10)
    {
        check = ft_putdec(nb / 10);
        if (check == -1)
            return (-1);
        count += check;
    }
    if (ft_putchar(base[nb % 10]) == -1)
        return (-1);
    return (count + 1);
}