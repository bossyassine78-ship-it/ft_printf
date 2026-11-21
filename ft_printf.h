/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-hil <yael-hil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:25:08 by yael-hil          #+#    #+#             */
/*   Updated: 2026/11/21 17:05:30 by yael-hil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_puthex_unsigned(unsigned long nb);
int	ft_puthex(unsigned long nb);
int	ft_putdec(long nb);
int	ft_putdec_unsigned(unsigned long nb);
int	check_arguments(char const p, va_list *ap);
int	print_argument(char const *format, va_list *ap);
int	for_p(void *ptr);

#endif
