#include "libftprintf.h"

int ft_putstr(void *str)
{
    char *c;
    int i;

    i = 0;
    if (!str)
    {
        char *n = "(null)";
        while (n[i])
        {
            ft_putchar(n[i]);
            i++;
        }
        return (i);
    }
    c = str;
    while (c[i])
    {
        ft_putchar(c[i]);
        i++;
    }
    return (i);
}