/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   check_arguments.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 19:25:27 by username         #+#    #+#              */
/*   Updated: 2026/11/23 20:03:40 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arguments(char const p, va_list *ap)
{
	if (p == 'd' || p == 'i')
		return (ft_putdec(va_arg(*ap, int)));
	else if (p == '%')
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	else if (p == 'p')
		return (for_p(va_arg(*ap, void *)));
	else if (p == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	else if (p == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (p == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int)));
	else if (p == 'X')
		return (ft_puthex_unsigned(va_arg(*ap, unsigned int)));
	else if (p == 'u')
		return (ft_putdec_unsigned(va_arg(*ap, unsigned int)));
	return (0);
}
