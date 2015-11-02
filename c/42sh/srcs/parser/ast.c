/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/08 14:58:03 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/10 20:18:58 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast		*ast_new(t_token *token)
{
	t_ast	*ast;

	ast = (t_ast*)malloc(sizeof(*ast));
	if (ast)
	{
		ast->tokens = (token ? ft_lstnew(token, sizeof(t_token)) : 0);
		ast->left = 0;
		ast->right = 0;
	}
	return (ast);
}

void		ast_free_node(t_ast *node)
{
	ft_lstdel(&node->tokens, (t_deleter)free);
	free(node);
}

void		ast_free(t_ast *node)
{
	if (node)
	{
		ast_free(node->left);
		ast_free(node->right);
		ast_free_node(node);
	}
}

void		ast_add_token_to_node(t_ast *node, t_token *token)
{
	t_list	*to_add;

	to_add = ft_lstnew(token, sizeof(t_token));
	ft_lstappend(&node->tokens, to_add);
}
