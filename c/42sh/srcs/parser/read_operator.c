/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:31:30 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/27 13:34:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int			read_op(char **stream, t_token *to_check, t_token *to_fill)
{
	size_t			len;

	len = ft_strlen(to_check->lexeme);
	if (!ft_strncmp(*stream, to_check->lexeme, len))
	{
		*stream += len;
		to_fill->type = to_check->type;
		to_fill->lexeme = ft_strdup(to_check->lexeme);
		return (1);
	}
	return (0);
}

int					read_operator(char **stream, t_token *token)
{
	size_t			i;
	static t_token	operators[] =

	{
	{OP_SEMI_COLON, ";"},
	{OP_LREDIR, "<"},
	{OP_DRREDIR, ">>"},
	{OP_RREDIR, ">"},
	{OP_OR, "||"},
	{OP_PIPE, "|"},
	{OP_AND, "&&"},
	{OP_AMPERSAND, "&"}
	};
	i = 0;
	while (i < sizeof(operators) / sizeof(t_token))
	{
		if (read_op(stream, operators + i, token))
			return (1);
		++i;
	}
	return (0);
}
