NAME = fillit.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c check.c read.c ft_supertab.c ft_putstr.c ft_putchar.c ft_putnbr.c

INCLUDES = libft.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:    %.c
	$(CC) $(FLAGS) -I=$(INCLUDES) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
