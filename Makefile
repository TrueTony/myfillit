NAME = fillit

SRCS = ./src/*.c
OBJ = ./src/*.o
HDR = ./src/fillit.h
LIBFT = libft/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(SRCS) -I $(HDR) -L. libft/libft.a 

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
