# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agfernan <agfernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 14:34:47 by agfernan          #+#    #+#              #
#    Updated: 2016/02/18 17:15:48 by agfernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC_FLAGS = -Wall -Werror -Wextra
SRC_DIR = .
HEADER_DIR = includes
OBJ_DIR = objects
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	  ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	  ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	  ft_atoi.c ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_strtrim.c \
	  ft_isprint.c ft_tolower.c ft_toupper.c ft_isascii.c ft_itoa.c \
	  ft_memalloc.c ft_memdel.c ft_putchar.c ft_putchar_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c \
	  ft_strclr.c ft_strdel.c ft_strjoin.c ft_striter.c ft_striteri.c \
	  ft_strequ.c ft_strmap.c ft_strmapi.c ft_strnequ.c ft_strnew.c \
	  ft_strsplit.c ft_strsub.c ft_lstdel.c ft_lstdelone.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_lstnew.c is_white_space.c put_str_tab.c \
	  get_point.c cmp_points.c get_partial_tab.c

OBJ = $(SRC:.c=.o)
	SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
	OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ))

all: $(NAME)

$(NAME):
		@gcc $(CC_FLAGS) -c $(SRCS) -I $(HEADER_DIR)
		@mkdir $(OBJ_DIR)
		@mv $(OBJ) $(OBJ_DIR)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
clean:
		@rm -rf $(OBJ_DIR)

fclean:
		@rm -rf $(OBJ_DIR) $(NAME)

re: fclean all
