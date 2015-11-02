/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 20:22:09 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:03:54 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "parser.h"
#include "environ.h"

static int	read_token(char **stream, t_token *token)
{
	size_t					i;
	static t_stream_reader	stream_readers[] =

	{
	read_color,
	read_var,
	read_command,
	read_chars
	};
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

static void	fetch_variable(t_context *context, t_token *token)
{
	char	*var_value;

	token->type = CHARS;
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

static void	post_process(t_context *context, t_list *tokens)
{
	t_token	*token;

	while (tokens)
	{
		token = (t_token *)tokens->content;
		if (token->type == VAR)
			fetch_variable(context, token);
		else if (token->type == COMMAND)
			fetch_command(context, token);
		tokens = tokens->next;
	}
}

t_list		*tokenize_prompt(t_context *context, char *format)
{
	t_token	token;
	int		ret;
	t_list	*tokens;

	tokens = 0;
	while ((ret = read_token(&format, &token)) == 1)
		ft_lstappend(&tokens, ft_lstnew(&token, sizeof(t_token)));
	if (ret == -1)
		ft_lstdel(&tokens, free_token);
	post_process(context, tokens);
	return (tokens);
}
