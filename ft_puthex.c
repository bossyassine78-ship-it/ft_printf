/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:24:40 by yael-hil          #+#    #+#             */
/*   Updated: 2026/11/20 23:23:58 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
