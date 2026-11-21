/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 22:42:53 by yael-hil          #+#    #+#             */
/*   Updated: 2026/11/21 17:14:44 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_db(char const *format, int *i, va_list *ap)
{
	int	check;

	if (format[*i] != '%' || (format[*i] == '%' && format[*i + 1] == '\0'))
	{
		if (ft_putchar(format[*i]) == -1)
			return (-1);
		return (1);
	}
	(*i)++;
	check = check_arguments(format[*i], ap);
	if (check == -1)
		return (-1);
	return (check);
}

int	print_argument(char const *format, va_list *ap)
{
	int	count;
	int	i;
	int	check;

	i = 0;
	count = 0;
	while (format[i])
	{
		check = print_db(format, &i, ap);
		if (check == -1)
			return (-1);
		count += check;
		i++;
	}
	return (count);
}
