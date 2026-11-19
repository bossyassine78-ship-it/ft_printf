/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printR.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:25:27 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:52:31 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	printr(char const p, va_list *ap)
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
		return (ft_putstrn(va_arg(*ap, void *)));
	else if (p == 'x')
		return (ft_puthex(va_arg(*ap, unsigned int)));
	else if (p == 'X')
		return (ft_puthexu(va_arg(*ap, unsigned int)));
	else if (p == 'u')
		return (ft_putdecu(va_arg(*ap, unsigned int)));
	return (0);
}
