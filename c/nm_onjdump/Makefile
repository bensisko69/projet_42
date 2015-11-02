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

NAME		= ft_nm.a

NAME_OTOOL	= ft_otool.a

SRC			= ft_nm.c\
			  ft_error.c\
			  trie.c\

SRC_OTOOL	= ft_otool.c\

OBJ_OTOOL	= $(SRC_OTOOL:.c=.o)

OBJ			= $(SRC:.c=.o)

FLAGS		= gcc -g3 -Wall -Werror -Wextra

LIB			= -L./libft -lft

LIB_FOLD	= libft/

HEADER		= -I ./includes

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_OTOOL)
	make -C $(LIB_FOLD)
	$(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	$(FLAGS) -o $(NAME_OTOOL) $(OBJ_OTOOL) $(LIB)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_OTOOL)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_OTOOL)
	make fclean -C $(LIB_FOLD)

re: fclean all