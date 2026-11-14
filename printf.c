
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
        if (format[i] != '%' || (format[i] == '%' && format[i+1] == '\0') )
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
            i++;
            if (format[i] == 'd' || format[i] == 'i')
            {
                count += ft_putdec(va_arg(ap,int));
            }
            else if (format[i] == '%')
            {
                count++;
                ft_putchar('%');
            }
            else if (format[i] == 'p')
            {
                ptr = va_arg(ap, void *);
                if (!ptr)
                {
                    count += ft_putstr("(nil)");
                }
                else
                {
                    ft_putstr("0x");
                    count += 2;
                    count += ft_puthex((unsigned long)ptr);
                }
            }
            else if (format[i] == 'c')
            {
                count++;
                ft_putchar(va_arg(ap,int));
            }
            else if (format[i] == 's')
            {
                count += ft_putstr(va_arg(ap,void *));
            }
            else if (format[i] == 'x')
            {
                count += ft_puthex(va_arg(ap,unsigned int));
            }
            else if (format[i] == 'X')
            {
                count += ft_puthexU(va_arg(ap,unsigned int));
            }
            else if (format[i] == 'u')
            {
                count += ft_putdecU(va_arg(ap,unsigned int));
            }
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

    n = ft_printf("%u|%x|%X\n", 0u, 0u, 0u);
    printf("return = %d (expected 6)\n", n);

    n = ft_printf("%u|%x|%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
    printf("return = %d (expected 29)\n", n);
    ft_printf("%%\n");
    ft_printf("%");
}