/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:25:08 by username          #+#    #+#             */
/*   Updated: 2026/11/19 22:55:11 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(char c);
int	ft_putstrn(char *str);
int	ft_puthexu(unsigned long nb);
int	ft_puthex(unsigned long nb);
int	ft_putdec(long nb);
int	ft_putdecu(unsigned long nb);
int	printr(char const p, va_list *ap);
int final_print(char const *format, va_list *ap);
int	for_p(void *ptr);

#endif
