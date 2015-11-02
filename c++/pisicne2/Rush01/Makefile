# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/11 17:07:19 by lrenoud-          #+#    #+#              #
#    Updated: 2015/04/19 14:02:39 by wburgos          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	ft_gkrellm
rwildcard		=	$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)\
					$(filter $(subst *,%,$2),$d))

COMPILER		=	clang++
CFLAGS			=	-Wall -Wextra -Werror -I .. -I Display/ -I Modules/ -c -g3
# -O3
QTINCLUDES		= 	-I $(HOME)/.brew/Cellar/qt5/5.4.1/include \
					-I $(HOME)/.brew/Cellar/qt5/5.4.1/include/QtCore \
					-I $(HOME)/.brew/Cellar/qt5/5.4.1/include/QtGui \
					-I $(HOME)/.brew/Cellar/qt5/5.4.1/include/QtWidgets
LFLAGS			=	-F $(HOME)/.brew/Cellar/qt5/5.4.1/lib -framework QtCore -framework QtGui -framework QtWidgets -lncurses

OBJ_DIR			=    objs
SRCS			=    $(call rwildcard, ./, *.cpp)
OBJS			=    $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

OBJ_SUB_DIRS	=    $(dir $(OBJS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "linking $@"
	@$(COMPILER) $^ $(LFLAGS) -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(foreach dir, $(OBJ_SUB_DIRS), mkdir -p $(dir);)

$(OBJ_DIR)/%.o: %.cpp
	@echo "compiling $(notdir $<)"
	@$(COMPILER) $(CFLAGS) $(QTINCLUDES) $< -o $@

depend: .depend

.depend: $(SRCS)
	@rm -f ./.depend
	@$(foreach src, $^, $(COMPILER) $(CFLAGS) $(QTINCLUDES) -MM -MT $(OBJ_DIR)/./$(src:.cpp=.o) $(src) >> ./.depend;)

-include .depend

clean:
	@echo "cleaning objects"
	@rm -rf $(OBJ_DIR)
	@rm -f ./.depend

fclean: clean
	@echo "cleaning $(NAME)"
	@rm -f $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
