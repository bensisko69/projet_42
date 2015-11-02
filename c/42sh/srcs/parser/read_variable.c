/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 16:26:21 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/17 19:19:40 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			read_variable(char **stream, t_token *token)
{
	char	*save;

	save = *stream;
	if (**stream == VARIABLE_PREFIX)
	{
		*stream += 2;
		while (**stream && **stream != ' ' && **stream != '\t')
			++(*stream);
		token->type = VARIABLE;
		token->lexeme = ft_strsub(save, 1, *stream - save - 1);
		return (1);
	}
	*stream = save;
	return (0);
}
