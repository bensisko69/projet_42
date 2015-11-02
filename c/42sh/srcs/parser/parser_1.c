/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 14:33:56 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:33:44 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
**	GRAMMAR :
**	exp				:=	command_list [OP_SEMICOLON]?
**	command_list	:=	and_or_command [OP_SEMICOLON command_list]?
**	and_or_command	:=	job [and_or_op and_or_command]?
**	job				:=	pipeline [OP_AMPERSAND [job]?]?
**	pipeline		:=	command [OP_PIPE pipeline]?
**	command			:=	simple_command [redirect]?
**	redirect		:=	[redirect_op WORD]*
**	redirect_op		:=	OP_LREDIR | OP_RREDIR | OP_DRREDIR
**	simple_command	:=	WORD arguments
**	arguments		:=	[WORD]*
**	and_or_op		:=	OP_AND | OP_OR
*/

static int	parse_job(t_list **tokens, t_ast **node)
{
	t_ast	*new_node;
	t_list	*save;

	new_node = ast_new(0);
	if (parse_pipeline(tokens, &new_node->left))
	{
		save = *tokens;
		if (parse_op_ampersand(tokens, &new_node))
		{
			parse_job(tokens, &new_node->right);
			*node = new_node;
			return (1);
		}
		*tokens = save;
		*node = new_node->left;
		ast_free_node(new_node);
		return (1);
	}
	ast_free_node(new_node);
	return (0);
}

static int	parse_and_or_command(t_list **tokens, t_ast **node)
{
	t_ast	*new_node;
	t_list	*save;

	new_node = ast_new(0);
	if (parse_job(tokens, &new_node->left))
	{
		save = *tokens;
		if (parse_and_or_op(tokens, &new_node))
		{
			if (!parse_and_or_command(tokens, &new_node->right))
			{
				ast_free(new_node);
				*tokens = save;
				return (0);
			}
			*node = new_node;
			return (1);
		}
		*tokens = save;
		*node = new_node->left;
		ast_free_node(new_node);
		return (1);
	}
	ast_free_node(new_node);
	return (0);
}

static int	parse_command_list(t_list **tokens, t_ast **node)
{
	t_ast	*new_node;
	t_list	*save;

	new_node = ast_new(0);
	if (parse_and_or_command(tokens, &new_node->left))
	{
		save = *tokens;
		if (parse_op_semi_colon(tokens, &new_node))
		{
			if (parse_command_list(tokens, &new_node->right))
			{
				*node = new_node;
				return (1);
			}
		}
		*tokens = save;
		*node = new_node->left;
		ast_free_node(new_node);
		return (1);
	}
	ast_free_node(new_node);
	return (0);
}

static int	parse_exp(t_list **tokens, t_ast **node)
{
	t_ast	*new_node;

	new_node = ast_new(0);
	if (parse_command_list(tokens, &new_node->left))
	{
		parse_op_semi_colon(tokens, &new_node);
		*node = new_node;
		return (1);
	}
	ast_free_node(new_node);
	return (0);
}

t_ast		*parse_tokens(t_list *tokens)
{
	t_ast	*root;
	t_ast	*true_root;

	if (!tokens)
		return (0);
	root = 0;
	if (parse_exp(&tokens, &root) && !tokens)
	{
		true_root = root;
		if (!root->tokens)
		{
			true_root = root->left;
			ast_free_node(root);
		}
		return (true_root);
	}
	ast_free(root);
	parse_error(tokens);
	return (0);
}
