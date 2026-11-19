/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexU.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:24:44 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:52:47 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthexu(unsigned long nb)
{
	char	*base;
	int		count;
	int		check;

	count = 0;
	check = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		check = ft_puthexu(nb / 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	if (ft_putchar(base[nb % 16]) == -1)
		return (-1);
	return (count + 1);
}
