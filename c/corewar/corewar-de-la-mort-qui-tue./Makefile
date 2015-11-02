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
			  parser/ft_list_push.c\
			  parser/main.c\
			parser/error_exit.c\
			parser/set_header.c\
			parser/record_instruction.c\
			parser/record_label.c\
			parser/verify_reg.c\
			parser/verify_dir.c\
			parser/verify_indir.c\
			parser/trim.c\
			parser/read_input.c\
			parser/iter_str.c\
			parser/array_tools.c\
			parser/is_blank.c\


OBJ			= $(SRC:.c=.o)

FLAGS		= -g3 -Wall -Werror -Wextra

LIB			= -L./libft -lft

LIB_FOLD	= libft/

HEADER		= -I 

all : $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_FOLD)
	$(CC) $(FLAGS) $(HEADER) -c $(SRC) $(LIB)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIB_FOLD)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIB_FOLD)

re: fclean all