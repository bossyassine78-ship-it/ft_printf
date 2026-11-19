/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_puthex.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 19:24:40 by username         #+#    #+#              */
/*   Updated: 2026/11/19 19:24:41 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(unsigned long nb)
{
	char	*base;
	int		count;
	int		check;

	count = 0;
	check = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		check = ft_puthex(nb / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar(base[nb % 16]) == -1)
		return (-1);
	return (count + 1);
}
