/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 20:35:53 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 18:17:02 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

int			exec_line(t_context *context, const char *line)
{
	t_list		*tokens;
	t_ast		*tree;

	tokens = tokenize(context, (char *)line);
	tree = parse_tokens(tokens);
	if (tree)
	{
		walk_ast(context, tree);
		ast_free(tree);
	}
	ft_lstdel(&tokens, free_token);
	return (1);
}
