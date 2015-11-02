/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:32:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/27 13:16:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "interpreter.h"
#include "builtins.h"

static void				init_context(t_context *context)
{
	context->env_vars = (t_env_vars *)ft_memalloc(sizeof(t_env_vars));
	context->vars = (t_vars *)ft_memalloc(sizeof(t_vars));
	context->commands = (t_commands *)ft_memalloc(sizeof(t_commands));
	environ_init(context->env_vars);
	list_commands(context);
}

t_context				*get_context(void)
{
	static t_context	*context = 0;

	if (!context)
	{
		context = (t_context *)ft_memalloc(sizeof(t_context));
		init_context(context);
	}
	return (context);
}

static void				free_job(void *p_job, size_t size)
{
	t_job				*job;

	UNUSED(size);
	job = (t_job *)p_job;
	job_clear(job);
	free(job);
}

void					free_context(t_context *context)
{
	environ_delete(context->env_vars);
	free(context->env_vars);
	variables_delete(context->vars);
	free(context->vars);
	commands_delete(context->commands);
	free(context->commands);
	ft_lstdel(&context->jobs, free_job);
	ft_dlist_delete(&context->history, free_history);
	free(context);
}
