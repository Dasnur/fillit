NAME = fillit

SRCS = srcs/validate.c srcs/get_tetrominos.c srcs/recursive_fill.c srcs/main.c

OBJS = srcs/validate.o srcs/get_tetrominos.o srcs/recursive_fill.o srcs/main.o

CFLAGS = gcc -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
    ($CFLAGS) -I .main.h -c $(SRCS)
    ($CFLAGS) -o $(NAME) $(OBJS) -L libft/ -lft

lib:
    make fclean
    make

clean:
    -rf $(OBJS)

fclean: clean
    -rf $(NAME)

re: fclean all