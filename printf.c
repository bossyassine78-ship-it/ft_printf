
#include "libftprintf.h"

int ft_printf(char const *format, ...)
{
    va_list ap;
    va_start(ap,format);
    int count ;
    void *ptr ;
    int i;
    int iff;

    i = 0;
    (void)iff;
    count = 0;
    while (format[i])
    {   
        if (format[i] != '%' || (format[i] == '%' && format[i+1] == '\0'))
        {
            iff = ft_putchar(format[i]);
            if (iff == -1)
            {
                va_end(ap);
                return (-1);
            }

            count++;
        }
        else if (format[i] == '%')
        {
            
        }
        i++;
    }
    va_end(ap);
    return (count);
}
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