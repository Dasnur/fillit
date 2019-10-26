NAME = fillit

SRCS =  sources/fillit.c sources/validate.c sources/get_tetrominos.c sources/recursive_fill.c \
		sources/set_cond.c

OBJ = fillit.o validate.o get_tetrominos.o recursive_fill.o set_cond.o 

CFLAGS = gcc -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): lib
	$(CFLAGS) -c $(SRCS) -Isources/ -Ilibft/
	$(CFLAGS) -o $(NAME) $(OBJ) -L libft -lft

lib:
	make -C libft

clean:
	-rm $(OBJ)
	make -C libft clean

fclean: clean
	-rm $(NAME)
	make -C libft fclean

re: fclean all
