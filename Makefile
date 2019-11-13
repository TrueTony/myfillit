NAME := fillit

SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib

SRC := count_of_tet.c fit.c lists.c main.c map.c rec.c tet_to_lst.c validate.c

OBJ := $(addprefix $(OBJ_DIR)/,$(SRC: .c=.o))

FLAGS := -Wall -Wextra -Werror

L_FT := $(LIB_DIR)/libft

include $(L_FT)/libft.mk

.PHONY: all clean fclean re

all:
	mkdir -p $(OBJ_DIR)
	@$(MAKE) -C $(L_FT)
	@$(MAKE) $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	gcc $(FLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LIB_LINK) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

relib:
	@$(MAKE) -C $(L_FT)
	@$(MAKE) re
