/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:25:14 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/26 18:33:37 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERPRETER_H
# define INTERPRETER_H

# include "parser.h"
# include "builtins.h"

/*
** Forwards
*/
typedef struct s_process	t_process;

typedef void	(*t_job_builder)(t_job *job, t_ast *);
typedef void	(*t_evaluator)(t_context *, t_ast *);

/*
** Error handling
*/
# define ERR_COMMAND_NOT_FOUND	"command not found"
# define ERR_EXECVE				"error executing"
# define ERR_PIPE				"pipe error"
# define ERR_FORK				"fork error"

# define EXEC_STATUS_OK			0
# define EXEC_STATUS_NOK		1

/*
** Top level node map
** Maps evaluators for OP_SEMI_COLON, OP_AMPERSAND, OP_AND and OP_OR
*/
t_map		*get_node_map(void);
void		free_node_map(void);
t_uint64	token_type_hash(const void *p_type);

void		eval_both(t_context *context, t_ast *node);
void		eval_in_background(t_context *context, t_ast *node);
void		eval_if_and(t_context *context, t_ast *node);
void		eval_if_or(t_context *context, t_ast *node);
void		eval_default(t_context *context, t_ast *node);

void		walk_ast(t_context *context, t_ast *ast);

/*
** Jobs
*/
struct		s_job
{
	t_list	*processes;
	int		last_pid;
	int		stdin_fd;
	int		stdout_fd;
	int		job_id;
	int		stopped;
	t_list	*token_values;
	char	*command_str;
};

void		free_job_init_map(void);
t_map		*get_job_init_map(void);

void		job_init(t_job *job, t_ast *node);
void		job_set_stdin(t_job *job, t_ast *node);
void		job_set_stdout_trunc(t_job *job, t_ast *node);
void		job_set_stdout_append(t_job *job, t_ast *node);
void		job_add_pipeline(t_job *job, t_ast *node);
void		job_add_process(t_job *job, t_ast *node);

int			job_start(t_context *context, t_ast *ast, int foreground);
void		exec_job(t_context *context, t_job *job);
void		job_clear(t_job *job);

/*
** Job control
*/
void		watch_job(t_context *context, t_job *job);
void		unwatch_job(t_context *context, t_job *job, int free_job);

void		job_add_tokens(t_job *job, t_ast *node);
void		job_start_notify(t_context *context, t_job *job);
void		show_finished_job(t_context *context, t_job *job, int status);

t_job		*last_run_job(t_context *context);
int			wait_job(t_job *job, int options, int *done_p);
void		put_job_in_foreground(t_context *context, t_job *job);
void		probe_jobs(t_context *context);
void		job_kill(t_job *job, int sig);

/*
** Processes
*/
struct		s_process
{
	t_list	*args;
	pid_t	pid;
	int		fd_in;
	int		fd_out;
};

void		start_process(t_context *context, t_process *process);

int			call_builtin(t_context *context, t_job *job, t_builtin builtin);
int			single_builtin(t_context *context, t_job *job, int *status);

/*
** IO
*/
# define APPEND_OFLAGS			(O_WRONLY | O_CREAT | O_APPEND)
# define TRUNC_OFLAGS			(O_WRONLY | O_CREAT | O_TRUNC)
# define CREATE_PERMISSIONS		(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

int			open_file(const char *file_name, int oflags, mode_t permissions);

# define PIPE_WRITE_END			1
# define PIPE_READ_END			0

int			exec_line(t_context *context, const char *line);
int			exec_file(t_context *context, const char *file_name);

#endif
