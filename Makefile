# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:37:34 by agfernan          #+#    #+#              #
#    Updated: 2016/02/18 17:16:25 by agfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC_FLAGS = -Wall -Werror -Wextra
SRC_DIR = srcs
HEADER_DIR = includes
LIB_DIR = libft
OBJ_DIR = objects
SRC = file_opening.c main.c checks.c tetri_construction.c resolve.c \
		checks_tetri.c resolve_2.c
OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME):
		@echo "Compiling libft"
		@make -C libft/ fclean && make -C libft/
		@echo "Creating objects"
		@gcc $(CC_FLAGS) -c $(SRCS) -I $(HEADER_DIR)
		@mkdir $(OBJ_DIR)
		@mv $(OBJ) $(OBJ_DIR)
		@echo "Compiling Fillit"
		@gcc -o $(NAME) $(OBJS) -I $(HEADER_DIR) -L $(LIB_DIR) -lft
		@echo "Executable created!"
clean:
		@echo "Removing objects"
		@rm -rf $(OBJ_DIR)
		@make -C libft/ clean

fclean:
		@echo "Removing objects and executable"
		@rm -rf $(OBJ_DIR) $(NAME)
		@make -C libft/ fclean

re: fclean all
