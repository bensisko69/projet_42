# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/27 14:37:53 by lrenoud-          #+#    #+#              #
#    Updated: 2015/10/28 16:18:10 by lrenoud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

INCLUDE_DIR = ./includes/

LIB_DIR = ./libft/includes/

SRC = lemin.c\
	  ft_error.c\
	  list.c\
	  parse.c\


OBJ = $(SRC:.c=.o)

LIBFT = ./libft/

FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIB_DIR)

all: libft/libft.a $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIBFT) -lft

libft/libft.a:
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean: cleanlib
	rm -f $(OBJ)

fclean: clean cleanlib
	rm -f $(NAME)

cleanlib:
	make -C ./libft clean

fcleanlib:
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re