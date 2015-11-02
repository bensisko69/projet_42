/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 19:53:20 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 12:59:39 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include "parser.h"

typedef enum e_prompt_token_type	t_prompt_token_type;

typedef char	*(*t_prompt_command)(t_context *, size_t);

enum	e_prompt_token_type
{
	CHARS,
	FG_COLOR,
	BG_COLOR,
	VAR,
	COMMAND
};

# define DEFAULT_PROMPT_1	"%B%{fg:45}%n%{fg:6}@{fg:33}%m%%b% "
# define DEFAULT_PROMPT		DEFAULT_PROMPT_1"{fg:27}%U%%I%%2c%%u%%i% {fg:255}> "
# define VAR_PS1			"PS1"

# define FG_COLOR_PREFIX	"\033[38;5;"
# define BG_COLOR_PREFIX	"\033[48;5;"
# define COLOR_SUFFIX		"m"
# define COLOR_PREFIX_SIZE	(sizeof(FG_COLOR_PREFIX) - 1)
# define COLOR_STR_SIZE		(COLOR_PREFIX_SIZE + sizeof(COLOR_SUFFIX) - 1)

/*
** Front end prompt display function
*/
void		show_prompt(t_context *context);
char		*format_prompt(t_context *context, const char *format);

t_list		*tokenize_prompt(t_context *context, char *format);
void		free_prompt_token(void *p_token, size_t size);

int			read_chars(char **stream, t_token *token);
int			read_color(char **stream, t_token *token);
int			read_var(char **stream, t_token *token);
int			read_command(char **stream, t_token *token);

void		fetch_command(t_context *context, t_token *token);
void		free_command_map(void);

# define DEFAULT_USER_NAME				"Anonymous"
# define USER_NAME_COMMAND				"n"

char		*user_name_command(t_context *context, size_t n);
# define NO_PWD							"<PWD not set>"
# define HOME_SHORTCUT_STR				"~"
# define PATH_COMMAND					"c"

char		*path_command(t_context *context, size_t n);
# define START_BOLD						"\033[1m"
# define START_BOLD_COMMAND				"B"

char		*start_bold_command(t_context *context, size_t n);
# define END_BOLD						"\033[0m"
# define END_BOLD_COMMAND				"b"

char		*end_bold_command(t_context *context, size_t n);
# define JOBS_NUMBER_COMMAND			"j"

char		*jobs_number_command(t_context *context, size_t n);
# define SH_LVL_COMMAND					"L"
# define DEFAULT_SH_LVL					"0"

char		*sh_lvl_command(t_context *context, size_t n);
# define START_UNDERLINE				"\033[4m"
# define START_UNDERLINE_COMMAND		"U"

char		*start_underline_command(t_context *context, size_t n);
# define END_UNDERLINE					"\033[24m"
# define END_UNDERLINE_COMMAND			"u"

char		*end_underline_command(t_context *context, size_t n);
# define LAST_STATUS_COMMAND			"?"

char		*last_status_command(t_context *context, size_t n);
# define TIME_24_COMMAND				"T"

char		*time_24_command(t_context *context, size_t n);
# define TIME_12_COMMAND				"t"

char		*time_12_command(t_context *context, size_t n);
# define START_ITALIC					"\033[3m"
# define START_ITALIC_COMMAND			"I"

char		*start_italic_command(t_context *context, size_t n);
# define END_ITALIC						"\033[23m"
# define END_ITALIC_COMMAND				"i"

char		*end_italic_command(t_context *context, size_t n);
# define START_REVERSE					"\033[7m"
# define START_REVERSE_COMMAND			"S"

char		*start_reverse_command(t_context *context, size_t n);
# define END_REVERSE					"\033[0m"
# define END_REVERSE_COMMAND			"s"

char		*end_reverse_command(t_context *context, size_t n);
# define NAME_MACHINE					"M"
# define MACHINE_NAME_ERROR				"MACHINE NAME HOST FAILED"

char		*name_machine_command(t_context *context, size_t n);
# define NAME_MACHINE_TRUNCATED			"m"

char		*name_machine_truncated_command(t_context *context, size_t n);

#endif
