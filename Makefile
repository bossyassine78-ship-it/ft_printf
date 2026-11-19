
NAME = libftprintf.a
CC = cc 
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Ilibft

SRC = printf.c ft_putchar.c ft_putdec.c ft_putdecU.c \
    	ft_puthex.c ft_puthexU.c ft_putstrN.c for_p.c \
			printR.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c libftprintf.h libft/libft.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re