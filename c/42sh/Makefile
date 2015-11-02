# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 19:04:59 by gudepard          #+#    #+#              #
#    Updated: 2014/03/27 18:39:07 by gudepard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	42sh

SRC_DIR				=	srcs
INCLUDE_DIR			=	includes
OBJ_DIR				=	objs

LIBFT				=	ft
LIBFT_DIR			=	libft
LIBFT_NAME			=	$(LIBFT_DIR)/libft.a
LIBFT_INCLUDE_DIR	=	$(LIBFT_DIR)/includes

COMPILER			=	gcc
CFLAGS				=	-O3 -Wall -Wextra -Werror -c \
						-I$(INCLUDE_DIR) -I$(LIBFT_INCLUDE_DIR)
LFLAGS				=	-L$(LIBFT_DIR) -l$(LIBFT) -ltermcap -o

# SOURCES
CONTEXT_DIR			=	context
CONTEXT_SRC			=	context.c \
						set_job.c \

VARIABLES_DIR		=	variables
VARIABLES_SRC		=	variables.c \

ENVIRON_DIR			=	environ
ENVIRON_SRC			=	environ_init.c    \
						environ_modif.c   \
						environ_display.c \
						environ_array.c   \

COMMANDS_DIR		=	commands
COMMANDS_SRC		=	list_commands.c \
						get_command.c   \

BUILTINS_DIR		=	builtins
BUILTINS_SRC		=	builtins.c \
						errors.c   \
						exit.c     \
						cd.c       \
						env.c      \
						env_exec.c \
						setenv.c   \
						unsetenv.c \
						echo.c     \
						vars.c     \
						set.c      \
						unset.c    \
						export.c   \
						pid.c      \
						source.c   \
						fg.c       \
						rainbow.c  \
						history.c  \

PARSER_DIR			=	parser
PARSER_SRC			=	tokens.c                \
						token_tools.c           \
						lexer.c                 \
						read_word.c             \
						read_operator.c         \
						read_variable.c         \
						parser_1.c              \
						parser_2.c              \
						terminal_parser.c       \
						parse_terminals_1.c     \
						parse_terminals_2.c     \
						terminal_predicates_1.c \
						terminal_predicates_2.c \
						post_process_tokens.c   \
						ast.c                   \
						parser_errors.c         \

INTERPRETER_DIR		=	interpreter
INTERPRETER_SRC		=	walk_ast.c          \
						node_map.c          \
						eval.c              \
						exec_line.c         \
						exec_file.c         \
						io.c                \
						job.c               \
						job_init_map.c      \
						job_builders.c      \
						job_notifications.c \
						exec_job.c          \
						wait_job.c          \
						process.c           \
						call_builtin.c      \
						watch_job.c         \
						job_control.c       \

SIGNALS_DIR			=	signals
SIGNALS_SRC			=	dispatch_signals.c   \
						signal_exit.c        \
						signal_interrupt.c   \
						signal_child.c       \
						signal_stop.c        \
						signals_name.c       \
						signals_name_map_1.c \
						signals_name_map_2.c \

PROMPT_DIR			=	prompt
PROMPT_SRC			=	show_prompt.c                     \
						format_prompt.c                   \
						prompt_lexer.c                    \
						prompt_readers.c                  \
						prompt_commands.c                 \
						user_name_command.c               \
						path_command.c                    \
						jobs_number_command.c             \
						start_bold_command.c              \
						end_bold_command.c                \
						sh_lvl_command.c                  \
						end_underline_command.c           \
						start_underline_command.c         \
						last_status_command.c             \
						time_24_command.c                 \
						time_12_command.c                 \
						start_italic_command.c            \
						end_italic_command.c              \
						start_reverse_command.c           \
						end_reverse_command.c             \
						name_machine_command.c            \
						name_machine_truncated_command.c  \

TERMCAPS_DIR		=	termcaps
TERMCAPS_SRC		=	terminal_modes.c     \
						tty.c                \
						term_command.c       \
						line_edit.c          \
						read_line.c          \
						handle_key.c         \
						key_map.c            \
						on_key_new_line.c    \
						on_key_tab.c         \
						on_key_backspace.c   \
						on_key_ctrl_d.c      \
						on_key_ctrl_l.c      \
						on_key_ctrl_w.c      \
						on_key_ctrl_k.c      \
						on_key_ctrl_a.c      \
						on_key_ctrl_e.c      \
						on_key_ctrl_u.c      \
						on_key_ctrl_h.c      \
						on_key_ctrl_g.c      \
						on_key_ctrl_c.c      \
						on_key_ctrl_f.c      \
						on_key_alt_left.c    \
						on_key_alt_right.c   \
						on_key_alt_up.c      \
						on_key_alt_down.c    \
						on_key_left_arrow.c  \
						on_key_right_arrow.c \
						on_key_up_arrow.c    \
						on_key_down_arrow.c  \

TOOLS_DIR			=	tools
TOOLS_SRC			=	path_join.c     \
						char_array.c    \
						file_stats.c    \
						str_replace.c   \
						join_str_list.c \

SRC					=	main.c        \
						shell_error.c \
						shell_exit.c  \

SRC					+=	$(addprefix $(CONTEXT_DIR)/, $(CONTEXT_SRC))
SRC					+=	$(addprefix $(VARIABLES_DIR)/, $(VARIABLES_SRC))
SRC					+=	$(addprefix $(ENVIRON_DIR)/, $(ENVIRON_SRC))
SRC					+=	$(addprefix $(COMMANDS_DIR)/, $(COMMANDS_SRC))
SRC					+=	$(addprefix $(BUILTINS_DIR)/, $(BUILTINS_SRC))
SRC					+=	$(addprefix $(PARSER_DIR)/, $(PARSER_SRC))
SRC					+=	$(addprefix $(INTERPRETER_DIR)/, $(INTERPRETER_SRC))
SRC					+=	$(addprefix $(SIGNALS_DIR)/, $(SIGNALS_SRC))
SRC					+=	$(addprefix $(PROMPT_DIR)/, $(PROMPT_SRC))
SRC					+=	$(addprefix $(TERMCAPS_DIR)/, $(TERMCAPS_SRC))
SRC					+=	$(addprefix $(TOOLS_DIR)/, $(TOOLS_SRC))
##

OBJ					=	$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(COMPILER) $(LFLAGS) $@ $^

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $@

# COMPILATION
$(OBJ_DIR)/%.o: $(SRC_DIR)/$(CONTEXT_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(VARIABLES_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(ENVIRON_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(COMMANDS_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(BUILTINS_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PARSER_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(INTERPRETER_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(SIGNALS_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PROMPT_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(TERMCAPS_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(TOOLS_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILER) $(CFLAGS) $^ -o $@
##

clean:
	rm -f $(OBJ)
	rm -df $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
