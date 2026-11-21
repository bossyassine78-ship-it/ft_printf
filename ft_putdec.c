/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:24:06 by yael-hil          #+#    #+#             */
/*   Updated: 2026/11/20 23:24:12 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(long nb)
{
	char	*base;
	int		count;
	int		check;

	base = "0123456789";
	count = 0;
	check = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count += 1;
		nb = -nb;
	}
	if (nb >= 10)
	{
		check = ft_putdec(nb / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar(base[nb % 10]) == -1)
		return (-1);
	return (count + 1);
}
