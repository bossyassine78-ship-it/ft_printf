#include "libftprintf.h"

int    ft_puthexU(unsigned long nb)
{
    char *base;
    int count;
    int check;
    
    count = 0;
    check = 0;
    base = "0123456789ABCDEF";
    if (nb >= 16)
    {
        check = ft_puthexU(nb / 16);
        if (check == -1)
            return (-1);
        count += check;
    }
    if (ft_putchar(base[nb % 16]) == -1)
        return (-1);
    return (count + 1);
}