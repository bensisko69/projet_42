# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/06 11:42:40 by lrenoud-          #+#    #+#              #
#    Updated: 2015/04/06 17:24:31 by lrenoud-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Awesome

SRC			= Awesome.class.cpp\
			  main.cpp\
			  add.cpp\
			  aff.cpp\


OBJ 		= $(SRC:.cpp=.o)

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

%.o: %.cpp
	clang++ $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	clang++ $^ -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all