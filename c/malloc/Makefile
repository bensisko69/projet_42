#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/23 18:12:19 by lrenoud-          #+#    #+#              #
#    Updated: 2014/09/23 18:12:20 by lrenoud-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME		= libft_malloc_$HOSTTYPE.so

SRC			= malloc.c\
			  free.c\

OBJ			= $(SRC:.c=.o)

FLAGS		= gcc -g3 -Wall -Werror -Wextra

LIB			= -L./libft -lft

LIB_FOLD	= libft/

HEADER		= -I ./includes

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_FOLD)
	$(FLAGS) -shared -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all