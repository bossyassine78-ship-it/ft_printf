#include "libftprintf.h"

int ft_putchar(char c)
{
    int x;
    x = write(1,&c,1);
    return (x);
}