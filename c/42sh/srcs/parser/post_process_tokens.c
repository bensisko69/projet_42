/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_process_tokens.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 15:57:56 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:31:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "environ.h"

static void	swap_tokens(t_list **tokens, t_list *redir, t_list *previous)
{
	t_list	*it;
	t_list	*tmp;
	t_token	*token;

	it = redir->next;
	while (it && it->next)
	{
		token = get_token(&it->next);
		if (token->type != WORD)
			break ;
		it = it->next;
	}
	if (it != redir->next)
	{
		tmp = redir->next->next;
		redir->next->next = it->next;
		it->next = redir;
		if (previous)
			previous->next = tmp;
		else
			*tokens = tmp;
	}
}

static int	is_redir_op_token(t_token *token)
{
	if (token)
	{
		if (token->type == OP_LREDIR
			|| token->type == OP_RREDIR
			|| token->type == OP_DRREDIR)
			return (1);
	}
	return (0);
}

void		rearrange_tokens(t_list **tokens)
{
	t_list	*it;
	t_list	*previous;

	it = *tokens;
	previous = 0;
	while (it)
	{
		if (is_redir_op_token((t_token *)it->content))
			swap_tokens(tokens, it, previous);
		previous = it;
		it = it->next;
	}
}

static void	fetch_variable(t_context *context, t_token *token)
{
	char	*var_value;

	token->type = WORD;
	if (!ft_strcmp(token->lexeme, "?"))
		var_value = ft_itoa(context->last_status);
	else
	{
		var_value = variables_get(context->vars, token->lexeme);
		if (!var_value)
			var_value = environ_get(context, token->lexeme);
		var_value = (var_value ? ft_strdup(var_value) : ft_strnew(0));
	}
	free(token->lexeme);
	token->lexeme = var_value;
}

void		replace_symbols(t_context *context, t_list *tokens)
{
	t_token	*token;
	char	*value;

	while (tokens)
	{
		token = (t_token *)tokens->content;
		if (token->type == VARIABLE)
			fetch_variable(context, token);
		else if (token->type == WORD && *token->lexeme == HOME_SHORTCUT)
		{
			value = environ_get(context, VAR_HOME);
			if (value)
			{
				value = ft_strjoin(value, token->lexeme + 1);
				free(token->lexeme);
				token->lexeme = value;
			}
		}
		tokens = tokens->next;
	}
}
