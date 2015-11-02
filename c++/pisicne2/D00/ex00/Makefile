# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/06 10:38:56 by lrenoud-          #+#    #+#              #
#    Updated: 2015/04/06 22:31:13 by lrenoud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

SRC			= megaphone.cpp

OBJ			= megaphone.o

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.cpp
	clang++  $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	clang++ $^ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all