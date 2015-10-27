# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/11 13:07:27 by lrenoud-          #+#    #+#              #
#    Updated: 2014/10/31 19:41:30 by lrenoud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc

SRC			= rrr.c\
			  rra.c\
			  rr.c\
			  ra.c\
			  pa.c\
			  main.c\
			  search.c\
			  ft_error.c\

OBJ			= $(SRC:.c=.o)

FLAGS		= -g3 -Wall -Werror -Wextra

LIB			= -L./libft -lft

LIB_FOLD	= libft/

HEADER		= -I ./includes

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_FOLD)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(HEADER) -c $(SRC) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all