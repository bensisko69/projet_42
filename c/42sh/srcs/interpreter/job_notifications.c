/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_notifications.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 14:46:17 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 19:04:07 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "termcaps.h"

void		job_start_notify(t_context *context, t_job *job)
{
	t_list			*it;
	t_process		*process;

	job->job_id = ft_lstsize(context->jobs) + 1;
	WRITE(tty_fd(), "[");
	ft_putnbr_fd(job->job_id, tty_fd());
	WRITE(tty_fd(), "]");
	it = job->processes;
	while (it)
	{
		process = (t_process *)it->content;
		WRITE(tty_fd(), " ");
		ft_putnbr_fd(process->pid, tty_fd());
		it = it->next;
	}
	WRITE(tty_fd(), "\n");
}

void		job_add_tokens(t_job *job, t_ast *node)
{
	t_list	*it;
	t_list	*str_list_link;
	char	*str;

	it = node->tokens;
	while (it)
	{
		str = get_token(&it)->lexeme;
		str_list_link = ft_lstnew(str, ft_strlen(str) + 1);
		ft_lstappend(&job->token_values, str_list_link);
		it = it->next;
	}
}

void		show_finished_job(t_context *context, t_job *job, int status)
{
	int		exit_code;

	WRITE(tty_fd(), "[");
	ft_putnbr_fd(job->job_id, tty_fd());
	WRITE(tty_fd(), "] ");
	if (job == last_run_job(context))
		WRITE(tty_fd(), "+ ");
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code == 0)
			WRITE(tty_fd(), "done");
		else
		{
			WRITE(tty_fd(), "exit ");
			ft_putnbr_fd(exit_code, tty_fd());
		}
	}
	else if (WIFSIGNALED(status))
		ft_putstr(signal_name(WTERMSIG(status)));
	WRITE(tty_fd(), "\t");
	ft_putendl_fd(job->command_str, tty_fd());
}
