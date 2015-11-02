#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 18:18:43 by lrenoud-          #+#    #+#              #
#    Updated: 2014/11/10 18:18:44 by lrenoud-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= asm

CC			= gcc

SRC			= parser/parser.c\
			  parser/ft_error.c\
			  parser/ft_list_push.c\
			  parser/main.c\
			  parser/check.c\
			  lexer/lexer.c\
			  lexer/type_para.c\
			  lexer/ft_error_lexer.c\
			  lexer/check_inst.c\
			  lexer/nb_cmt_or_name.c\
			  lexer/live.c\

OBJ			= $(SRC:.c=.o)

FLAGS		= -g3 -Wall -Werror -Wextra

LIB			= -L./libft -lft

LIB_FOLD	= libft/

HEADER		= -I 

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_FOLD)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all