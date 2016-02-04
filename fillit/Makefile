# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 14:37:34 by agfernan          #+#    #+#              #
#    Updated: 2016/02/04 21:45:25 by cchampda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC_FLAGS = -Wall -Werror -Wextra
SRC_DIR = srcs
HEADER_DIR = includes
LIB_DIR = libft
OBJ_DIR = objects
SRC = file_opening.c main.c checks.c tetri_construction.c addtolib.c resolve.c \

OBJ = $(SRC:.c=.o)
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME):
		gcc $(CC_FLAGS) -c $(SRCS) -I $(HEADER_DIR)
		mkdir $(OBJ_DIR)
		mv $(OBJ) $(OBJ_DIR)
		gcc -o $(NAME) $(OBJS) -I $(HEADER_DIR) -L $(LIB_DIR) -lft
clean:
		rm -rf $(OBJ_DIR)

fclean:
		rm -rf $(OBJ_DIR) $(NAME)

re: fclean all
