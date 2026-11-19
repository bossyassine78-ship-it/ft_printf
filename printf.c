/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:25:24 by username          #+#    #+#             */
/*   Updated: 2026/11/19 23:11:09 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int count;

	count = 0;
	va_start(ap, format);
	count = final_print(format,&ap);
	va_end(ap);
	return (count);
}