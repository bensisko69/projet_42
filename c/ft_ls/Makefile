# **************************************************************************** #
#                                                                              #
#                                                        :::      ::::::::     #
#    Makefile                                           :+:      :+:    :+:    #
#                                                    +:+ +:+         +:+       #
#    By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+         #
#                                                +#+#+#+#+#+   +#+             #
#    Created: 2013/11/28 15:16:08 by lrenoud-          #+#    #+#              #
#    Updated: 2013/11/28 17:16:42 by lrenoud-         ###   ########.fr        #
#                                                                              #
# ***************************************************************************  #

NAME = ft_ls

LIB_DIR = ./libft

SRC = main.c\
	  ft_ls.c\
	  ft_a.c\
	  ft_new_link.c\
	  ft_add_start.c\
	  ft_perm.c\
	  ft_insert.c\
	  ft_r.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	@(cd $(LIB_DIR) && $(MAKE))

$(NAME):
	@gcc -c $(FLAG) $(SRC)
	@gcc -o $(NAME) $(OBJ) -L$(LIB_DIR) -lft

clean:
	@rm -f $(OBJ)

fclean: fcleanlib clean
	@rm -f $(NAME)

fcleanlib:
	@(cd $(LIB_DIR) && $(MAKE) fclean)

re: fcleanlib fclean all
