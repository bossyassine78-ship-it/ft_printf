#include "libftprintf.h"

int	for_p(void *ptr)
{
	int	count;
	int	check;

	check = 0;
	count = 0;
	if (!ptr)
	{
		if(write(1, "(nil)", 5) < 0)
			return -1;
		return (5);
	}
	else
	{
		check = ft_puthex((unsigned long)ptr);
		if (check == -1)
			return (-1);
		count += ft_putstr("0x");
		count += check;
	}
	return (count);
}

int printR(void *p,va_list ap)
{
	int	i;
	void	*ptr;
	int	count;

	i = 0;
	count = 0;
    	if (format[i] == 'd' || format[i] == 'i')
    	{
		count += ft_putdec(va_arg(ap, int));
	}
	else if (format[i] == '%')
	{
		iff = ft_putchar('%');
		if (iff == -1)
		{
			va_end(ap);
			return (-1);
		}
		count++;
	}
	else if (format[i] == 'p')
	{
		ptr = va_arg(ap, void *);
		if (!ptr)
			count += ft_putstr("(nil)");
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
		ft_putchar(va_arg(ap, int));
	}
	else if (format[i] == 's')
		count += ft_putstr(va_arg(ap, void *));
	else if (format[i] == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (format[i] == 'X')
		count += ft_puthexU(va_arg(ap, unsigned int));
	else if (format[i] == 'u')
		count += ft_putdecU(va_arg(ap, unsigned int));
	return (count);
}
