/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   print_argument.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 22:42:53 by username         #+#    #+#              */
/*   Updated: 2026/11/23 20:03:35 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	char	*v;
	int		i;

	v = "cspdiuxX%";
	i = 0;
	while (v[i])
	{
		if (v[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	print_db(char const *format, int *i, va_list *ap)
{
	if (format[*i] != '%')
		return (ft_putchar(format[*i]));
	(*i)++;
	if (format[*i] == '\0')
		return (-1);
	if (is_valid(format[*i]))
		return (check_arguments(format[*i], ap));
	(*i)--;
	return (ft_putchar('%'));
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
