
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = check_arguments.c ft_printf.c ft_putdec.c ft_puthex.c ft_putstr.c \
	  for_p.c ft_putchar.c ft_putdec_unsigned.c ft_puthex_unsigned.c \
	  print_argument.c
OBJ = $(SRC:.c=.o)


all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re