/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 17:19:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/13 20:18:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

/*
** For each traversed node, find the evaluator function corresponding to the
** type of the first token of that node
*/
void			walk_ast(t_context *context, t_ast *node)
{
	t_evaluator	evaluator;
	t_token		*token;

	if (node)
	{
		token = (t_token *)node->tokens->content;
		evaluator = (t_evaluator)ft_map_get(*get_node_map(),
											&token->type,
											token_type_hash);
		if (!evaluator)
			evaluator = eval_default;
		evaluator(context, node);
	}
}
