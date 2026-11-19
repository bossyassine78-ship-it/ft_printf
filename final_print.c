/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 22:42:53 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:50:08 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int final_print(char const *format, va_list *ap)
{
    int		count;
	int		i;
	int		check;
    
    i = 0;
	check = 0;
	count = 0;
    while (format[i])
	{
		if (format[i] != '%' || (format[i] == '%' && format[i + 1] == '\0'))
		{
			if (ft_putchar(format[i]) == -1)
			{
                return (-1);
			}
			count++;
		}
		else if (format[i] == '%')
		{
			if (printr(format[i + 1], ap) != -1)
				count += check;
			else
			{
                return (-1);
			}
		}
		i++;
	}
    return (count);
}