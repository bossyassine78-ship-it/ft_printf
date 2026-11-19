#include "libftprintf.h"

int main()
{
   int n;

    n = ft_printf("%u|%x|%X\n", 42u, 42u, 42u);
    printf("return = %d (expected 9)\n", n);

    n = ft_printf("AYOUUUB\n");
    printf("return = %d (expected 8)\n", n);

    n = ft_printf("%u|%x|%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
    printf("return = %d (expected 29)\n", n);
    ft_printf("%%\n");
    ft_printf("A%%B\n");
}