/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 23:10:05 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:36:44 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			terminal(t_list **tokens, int type)
{
	if (*tokens)
		return (get_token(tokens)->type == type);
	return (0);
}

void		next_token(t_list **tokens)
{
	*tokens = (*tokens)->next;
}

t_token		*get_token(t_list **tokens)
{
	t_token	*token;

	token = (t_token *)((*tokens)->content);
	return (token);
}

void		free_token(void *p_token, size_t size)
{
	t_token	*token;

	UNUSED(size);
	token = (t_token *)p_token;
	free(token->lexeme);
	free(token);
}

char		*token_value(t_list *tokens, size_t index)
{
	while (index-- > 1)
	{
		if (tokens)
			tokens = tokens->next;
		else
			return (0);
	}
	if (!tokens)
		return (0);
	return (get_token(&tokens)->lexeme);
}
