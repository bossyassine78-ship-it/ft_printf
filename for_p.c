#include "libftprintf.h"

int	for_p(void *ptr)
{
    int check;

    check = 0;
	if (!ptr)
	{
		if(write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	else
	{
		check = ft_puthex((unsigned long)ptr);
		if (check == -1)
			return (-1);
		ft_putstrN("0x");
	}
	return (check + 2);
}
