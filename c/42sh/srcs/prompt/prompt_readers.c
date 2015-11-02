/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_readers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 20:46:10 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 16:52:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static int	read_number(char **stream, t_token *token)
{
	char	*save;
	char	*nbr;
	t_uchar	color;

	save = *stream;
	while (ft_isdigit(**stream))
		++(*stream);
	if (save == *stream || **stream != '}')
		return (0);
	nbr = ft_strsub(save, 0, *stream - save);
	color = (t_uchar)ft_atoi(nbr);
	token->lexeme = ft_itoa(color);
	free(nbr);
	++(*stream);
	return (1);
}

int			read_color(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	if (**stream == '{')
	{
		if (!ft_strncmp(*stream + 1, "fg:", 3))
			token->type = FG_COLOR;
		else if (!ft_strncmp(*stream + 1, "bg:", 3))
			token->type = BG_COLOR;
		else
			return (0);
		*stream += 4;
		if (read_number(stream, token))
			return (1);
	}
	*stream = save;
	return (0);
}

int			read_var(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	if (**stream == '{' && *(*stream + 1) == '$')
	{
		*stream += 2;
		while (**stream
				&& **stream != ' '
				&& **stream != '\t'
				&& **stream != '}')
			++(*stream);
		if (**stream == '}' && *stream - 2 != save)
		{
			token->type = VAR;
			token->lexeme = ft_strsub(save, 2, *stream - save - 2);
			++(*stream);
			return (1);
		}
	}
	*stream = save;
	return (0);
}

int			read_command(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	if (**stream == '%')
	{
		++(*stream);
		while (**stream
				&& **stream != ' '
				&& **stream != '\t'
				&& **stream != '%')
			++(*stream);
		if (**stream == '%' && *stream - 1 != save)
		{
			token->type = COMMAND;
			token->lexeme = ft_strsub(save, 1, *stream - save - 1);
			++(*stream);
			return (1);
		}
	}
	*stream = save;
	return (0);
}

int			read_chars(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	while (**stream && **stream != '{' && **stream != '%')
		++(*stream);
	if (*stream == save)
		return (0);
	token->type = CHARS;
	token->lexeme = ft_strsub(save, 0, *stream - save);
	return (1);
}
