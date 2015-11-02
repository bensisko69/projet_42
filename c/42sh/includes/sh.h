/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 19:23:16 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 15:38:58 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <term.h>

# include "libft.h"

/*
** Forwards
*/
typedef struct s_context	t_context;

typedef t_map				t_env_vars;
typedef t_map				t_vars;
typedef t_map				t_commands;

typedef struct dirent		t_dirent;

typedef struct s_job		t_job;

typedef struct termios		t_termios;

/*
** Error handling
*/
# define EXIT_SUCCESS			0
# define EXIT_ERROR				1

# define SHELL_ERROR_PREFIX		"42sh"

# define ERR_NO_SUCH_FILE		"no such file or directory"
# define ERR_DENIED				"permission denied"
# define ERR_UNKNOWN			"unknown error"

void		shell_error(const char *what, const char *info);

/*
** Final exit function
** Always use it before exiting (even if the case should be rare)
*/
void		shell_exit(t_context *context, int exit_code);

/*
** Main context
*/
struct		s_context
{
	t_env_vars	*env_vars;
	t_vars		*vars;
	t_commands	*commands;
	t_list		*jobs;
	t_job		*busy_job;
	int			probe_jobs;
	int			do_susp;
	int			last_status;
	t_termios	term_state;
	t_dlist		*history;
	t_dlist		*history_ptr;
};

void		set_fg_job(t_context *context, t_job *job);

/*
** Singleton to access the shell context
** Usefull when signal handlers need to act on the context
** DO NOT USE IT JUST BECAUSE YOU ARE LAZY
** A singleton is not more than a hidden global and a misuse of it is equivalent
** to using an unjustified global
*/
t_context	*get_context(void);
void		free_context(t_context *context);

/*
** List commands in the PATH
** Add the command name and its corresponding full path in the context's hashmap
*/
void		list_commands(t_context *context);
void		commands_delete(t_commands *commands);
# define PATH_DIR_SEPARATOR		':'

char		*get_command_path(t_context *context, const char *command_name);

/*
** User local variables
*/
char		*variables_get(t_vars *vars, const char *key);
void		variables_set(t_vars *vars, const char *key, const char *value);
void		variables_remove(t_vars *vars, const char *key);
void		variables_delete(t_vars *vars);

# define HOME_SHORTCUT			'~'

/*
** Signals handling
*/
void		dispatch_signals(void);
void		reset_signals(void);

void		on_signal_exit(int sig);
void		on_signal_interrupt(int sig);
void		on_signal_child(int sig);
void		on_signal_stop(int sig);

char		*signal_name(int signal);
t_map		*get_signal_names_map(void);
void		free_signal_names_map(void);
t_uint64	signal_id_hash(const void *p_id);

# define SIG_NAME_HUP			"hangup"
# define SIG_NAME_INT			"interrupt"
# define SIG_NAME_QUIT			"quit"
# define SIG_NAME_ILL			"illegal hardware instruction"
# define SIG_NAME_TRAP			"trace trap"
# define SIG_NAME_ABRT			"abort"
# define SIG_NAME_EMT			"EMT instruction"
# define SIG_NAME_FPE			"floating point exception"
# define SIG_NAME_KILL			"killed"
# define SIG_NAME_BUS			"bus error"
# define SIG_NAME_SEGV			"segmentation fault"
# define SIG_NAME_SYS			"invalid system call"
# define SIG_NAME_PIPE			"broken pipe"
# define SIG_NAME_ALRM			"alarm"
# define SIG_NAME_TERM			"terminated"
# define SIG_NAME_URG			"urgent condition"
# define SIG_NAME_STOP			"suspended"
# define SIG_NAME_TSTP			"suspended"
# define SIG_NAME_CONT			"continued"
# define SIG_NAME_CHLD			"child status changed"
# define SIG_NAME_TTIN			"suspended (tty input)"
# define SIG_NAME_TTOU			"suspended (tty output)"
# define SIG_NAME_IO			"I/O"
# define SIG_NAME_XCPU			"cpu limit exceeded"
# define SIG_NAME_XFSZ			"file size limit exceeded"
# define SIG_NAME_VTALRM		"virtual time alarm"
# define SIG_NAME_PROF			"profile signal"
# define SIG_NAME_WINCH			"Window size change"
# define SIG_NAME_INFO			"Status request from keyboard"
# define SIG_NAME_USR1			"user-defined signal 1"
# define SIG_NAME_USR2			"user-defined signal 2"
# define SIG_NAME_UNKNOWN		"unknown signal"

#endif
