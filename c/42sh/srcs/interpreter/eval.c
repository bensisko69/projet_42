/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 17:13:17 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/23 00:30:37 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

void	eval_both(t_context *context, t_ast *node)
{
	walk_ast(context, node->left);
	walk_ast(context, node->right);
}

void	eval_in_background(t_context *context, t_ast *node)
{
	job_start(context, node->left, 0);
	walk_ast(context, node->right);
}

void	eval_if_and(t_context *context, t_ast *node)
{
	if (job_start(context, node->left, 1) && !context->busy_job)
		walk_ast(context, node->right);
}

void	eval_if_or(t_context *context, t_ast *node)
{
	if (!job_start(context, node->left, 1) && !context->busy_job)
		walk_ast(context, node->right);
}

void	eval_default(t_context *context, t_ast *node)
{
	job_start(context, node, 1);
}
