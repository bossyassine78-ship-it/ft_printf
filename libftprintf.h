
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>

int ft_printf(char const *format, ...);
int ft_putchar(char c);
int ft_putstr(void *str);
int    ft_puthexU(long nb);
int    ft_puthex(unsigned long nb);
int   ft_putdec(long nb);
size_t   ft_putdecU(unsigned long nb);

#endif