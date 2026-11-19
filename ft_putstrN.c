#include "libftprintf.h"

int ft_putstrN(char *str)
{
    int i;
    int check;

    i = 0;
    check = 0;
    if (!str)
    {
        if (write (1, "null", 6) == -1)
            return (-1);
        return (6);
    }
    while (str[i])
    {
        check = ft_putchar(str[i]);
        if (check == -1)
                return (-1);
        i++;
    }
    return (i);
}