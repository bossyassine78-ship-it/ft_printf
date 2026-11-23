/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 19:25:08 by username         #+#    #+#              */
/*   Updated: 2026/11/23 20:03:46 by username        ###   ########.fr        */
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
