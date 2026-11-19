/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstrN.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 19:24:53 by username         #+#    #+#              */
/*   Updated: 2026/11/19 19:24:58 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstrn(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (!str)
	{
		if (write(1, "null", 5) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		check = ft_putchar(str[i]);
		if (check == -1)
			return (-1);
		i++;
	}
	return (i);
}
