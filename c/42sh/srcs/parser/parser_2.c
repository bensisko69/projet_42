/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:26:51 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:34:10 by lrenoud-         ###   ########.fr       */
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

static int	parse_arguments(t_list **tokens, t_ast **node)
{
	while (parse_word(tokens, node))
		continue ;
	return (1);
}

static int	parse_simple_command(t_list **tokens, t_ast **node)
{
	if (parse_word(tokens, node))
	{
		parse_arguments(tokens, node);
		return (1);
	}
	return (0);
}

static int	parse_redirect(t_list **tokens, t_ast **node)
{
	t_ast	*new_node_redir;
	t_ast	*new_node_word;
	t_list	*save;

	new_node_redir = ast_new(0);
	new_node_word = ast_new(0);
	save = *tokens;
	if (parse_redirect_op(tokens, &new_node_redir))
	{
		if (parse_word(tokens, &new_node_word))
		{
			new_node_redir->right = new_node_word;
			parse_redirect(tokens, &new_node_word->right);
			*node = new_node_redir;
			return (1);
		}
	}
	*tokens = save;
	ast_free_node(new_node_redir);
	ast_free_node(new_node_word);
	return (0);
}

static int	parse_command(t_list **tokens, t_ast **node)
{
	t_ast	*new_node_command;
	t_ast	*new_node_redir;

	new_node_command = ast_new(0);
	new_node_redir = 0;
	if (parse_simple_command(tokens, &new_node_command))
	{
		if (parse_redirect(tokens, &new_node_redir))
		{
			new_node_redir->left = new_node_command;
			*node = new_node_redir;
		}
		else
		{
			*node = new_node_command;
			ast_free_node(new_node_redir);
		}
		return (1);
	}
	ast_free_node(new_node_command);
	ast_free_node(new_node_redir);
	return (0);
}

int			parse_pipeline(t_list **tokens, t_ast **node)
{
	t_ast	*new_node;
	t_list	*save;

	new_node = ast_new(0);
	if (parse_command(tokens, &new_node->left))
	{
		save = *tokens;
		if (parse_op_pipe(tokens, &new_node))
		{
			if (!parse_pipeline(tokens, &new_node->right))
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
