/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:23:55 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:53:34 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	for_p(void *ptr)
{
	int	check;

	check = 0;
	if (!ptr)
	{
		if (write(1, "(nil)", 5) < 0)
			return (-1);
		return (5);
	}
	else
	{
		check = ft_puthex((unsigned long) ptr);
		if (check == -1)
			return (-1);
		ft_putstrn("0x");
	}
	return (check + 2);
}
