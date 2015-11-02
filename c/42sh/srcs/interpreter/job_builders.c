/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_builders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:18:31 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 19:36:37 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "interpreter.h"

void			job_set_stdin(t_job *job, t_ast *node)
{
	char		*file_name;

	if (job->stdin_fd != STDIN)
		close(job->stdin_fd);
	file_name = token_value(node->right->tokens, 1);
	job->stdin_fd = open_file(file_name, O_RDONLY, 0);
	job_init(job, node->left);
	job_add_tokens(job, node);
	job_add_tokens(job, node->right);
	job_init(job, node->right->right);
}

void			job_set_stdout_trunc(t_job *job, t_ast *node)
{
	char		*file_name;

	if (job->stdout_fd != STDOUT)
		close(job->stdout_fd);
	file_name = token_value(node->right->tokens, 1);
	job->stdout_fd = open_file(file_name, TRUNC_OFLAGS, CREATE_PERMISSIONS);
	job_init(job, node->left);
	job_add_tokens(job, node);
	job_add_tokens(job, node->right);
	job_init(job, node->right->right);
}

void			job_set_stdout_append(t_job *job, t_ast *node)
{
	char		*file_name;

	if (job->stdout_fd != STDOUT)
		close(job->stdout_fd);
	file_name = token_value(node->right->tokens, 1);
	job->stdout_fd = open_file(file_name, APPEND_OFLAGS, CREATE_PERMISSIONS);
	job_init(job, node->left);
	job_add_tokens(job, node);
	job_add_tokens(job, node->right);
	job_init(job, node->right->right);
}

void			job_add_pipeline(t_job *job, t_ast *node)
{
	job_init(job, node->left);
	job_add_tokens(job, node);
	job_init(job, node->right);
}

void			job_add_process(t_job *job, t_ast *node)
{
	t_process	process;
	t_list		*process_list_link;

	ft_bzero(&process, sizeof(t_process));
	process.fd_in = STDIN;
	process.fd_out = STDOUT;
	process.args = node->tokens;
	process_list_link = ft_lstnew(&process, sizeof(t_process));
	job_add_tokens(job, node);
	ft_lstappend(&job->processes, process_list_link);
}
