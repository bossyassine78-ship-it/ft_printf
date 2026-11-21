/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:23:55 by yael-hil          #+#    #+#             */
/*   Updated: 2026/11/21 17:02:51 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	for_p(void *ptr)
{
	int	count;
	int	check;

	if (!ptr)
		return (ft_putstr("(nil)"));
	check = ft_putstr("0x");
	if (check == -1)
		return (-1);
	count = check;
	check = ft_puthex((unsigned long)ptr);
	if (check == -1)
		return (-1);
	return (count + check);
}
