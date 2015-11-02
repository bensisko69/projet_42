/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:44:51 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:30:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

static void	ignore_whitespaces(char **stream)
{
	while (is_whitespace(**stream))
		++(*stream);
}

static int	read_token(char **stream, t_token *token)
{
	size_t					i;
	static t_stream_reader	stream_readers[] =

	{
	read_operator,
	read_variable,
	read_word
	};
	ignore_whitespaces(stream);
	if (!**stream)
		return (0);
	i = 0;
	while (i < sizeof(stream_readers) / sizeof(t_stream_reader))
	{
		if (stream_readers[i](stream, token))
			return (1);
		++i;
	}
	return (-1);
}

t_list		*tokenize(t_context *context, char *string)
{
	t_list	*tokens;
	t_token	token;
	int		ret;

	tokens = 0;
	while ((ret = read_token(&string, &token)) == 1)
		ft_lstappend(&tokens, ft_lstnew(&token, sizeof(t_token)));
	if (ret == -1)
	{
		syntax_error(tokens);
		ft_lstdel(&tokens, free_token);
	}
	else
	{
		rearrange_tokens(&tokens);
		replace_symbols(context, tokens);
	}
	return (tokens);
}
