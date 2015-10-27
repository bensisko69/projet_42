#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/09/25 12:32:20 by lrenoud-          #+#    #+#              #
#    Updated: 2014/09/25 12:32:21 by lrenoud-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

INCLUDE_DIR = ./includes/

LIB_DIR = ./libft/includes/

SRC = fdf.c\
	  display.c\
	  draw_line_x.c\
	  convers.c\
	  parse.c\

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/

FLAGMLX = -lmlx -framework OpenGL -framework AppKit

PATHMLX = /nfs/zfs-student-3/users/2013/lrenoud-/minilibx_macos

FLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDE_DIR) -I$(LIB_DIR)

all: libft/libft.a $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -L$(LIBFT) -lft -L$(PATHMLX) $(FLAGMLX)

libft/libft.a:
	make -C libft

%.o: %.c
	gcc $(FLAGS) -c $^

clean: cleanlib
	rm -f $(OBJ)

fclean: clean fcleanlib
	rm -f $(NAME)

cleanlib:
	make -C ./libft clean

fcleanlib:
	make -C ./libft fclean

re: fclean all
