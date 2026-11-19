/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:24:10 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:52:42 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putdecu(unsigned long nb)
{
	char	*base;
	int		count;
	int		check;

	base = "0123456789";
	count = 0;
	check = 0;
	if (nb >= 10)
	{
		check = ft_putdecu(nb / 10);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar(base[nb % 10]) == -1)
		return (-1);
	return (count + 1);
}
