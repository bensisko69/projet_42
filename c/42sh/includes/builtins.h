/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 17:58:21 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 18:38:47 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "sh.h"

/*
** Forwards
*/
typedef t_map				t_builtins;
typedef	struct s_history	t_history;

struct		s_history
{
	size_t	entry_number;
	char	*entry;
};

/*
** Builtins function should have the same prototype, for the sake of consistency
** and easier maintenance. Please also prefix front-end fonctions with 'b_'
** They need a context to act upon and the argument list of the invocation
** The list will be a t_list<t_token> which will contain the name of the builtin
** followed by all the arguments which should be all WORDs
*/
typedef int					(*t_builtin)(t_context *, t_list *);

/*
** Error handling
*/
# define BUILTIN_ERROR			1
# define BUILTIN_SUCCESS		0

# define ERR_SEPARATOR			": "
# define ERR_TOO_MANY_ARGS		"too many arguments"
# define ERR_TOO_FEW_ARGS		"too few arguments"
# define ERR_ILLEGAL_OPTION		"illegal option"

int			builtin_error(const char *name, const char *err, const char *info);

/*
** Singleton to access the builtins map
*/
t_builtins	*get_builtins(void);
void		free_builtins(void);

/*
** Front end function to retrieve a builtin function pointer
*/
t_builtin	get_builtin(const char *command_name);

/*
** cd
*/
# define CD_BUILTIN				"cd"

int			b_cd(t_context *context, t_list *args);
# define ERR_NO_HOME			"no home directory set"
# define ERR_STRING_NOT_IN_PWD	"string is not in pwd"

/*
** echo
*/
# define ECHO_BUILTIN			"echo"

int			b_echo(t_context *context, t_list *args);
/*
** exit
*/
# define EXIT_BUILTIN			"exit"

int			b_exit(t_context *context, t_list *args);
/*
** env
*/
# define ENV_BUILTIN			"env"

int			b_env(t_context *context, t_list *args);
int			env_exec(t_context *context, t_list *args, int rm, t_list *add);
/*
** setenv
*/
# define SETENV_BUILTIN			"setenv"

int			b_setenv(t_context *context, t_list *args);
/*
** unsetenv
*/
# define UNSETENV_BUILTIN		"unsetenv"

int			b_unsetenv(t_context *context, t_list *args);
/*
** vars
*/
# define VARS_BUILTIN			"vars"
# define VARS_SEPARATOR			" -> "

int			b_vars(t_context *context, t_list *args);
/*
** set
*/
# define SET_BUILTIN			"set"

int			b_set(t_context *context, t_list *args);
# define ERR_INVALID_NAME		"invalid name"

/*
** unset
*/
# define UNSET_BUILTIN			"unset"

int			b_unset(t_context *context, t_list *args);
/*
** export
*/
# define EXPORT_BUILTIN			"export"

int			b_export(t_context *context, t_list *args);
/*
** pid
*/
# define PID_BUILTIN			"pid"

int			b_pid(t_context *context, t_list *args);
/*
** source
*/
# define SOURCE_BUILTIN			"source"

int			b_source(t_context *context, t_list *args);
/*
** fg
*/
# define FG_BUILTIN				"fg"

int			b_fg(t_context *context, t_list *args);
# define ERR_NO_CURRENT_JOB		"no current job"

/*
** rainbow
*/
# define RAINBOW_BUILTIN		"rainbow"

int			b_rainbow(t_context *context, t_list *args);
/*
** history
*/
# define HISTORY_BUILTIN		"history"
# define BASE_HISTORY_DISPLAY	20

int			b_history(t_context *context, t_list *args);
void		history_add(t_context *context, const char *command_line);
void		free_history(void *p_history, size_t size);

#endif
