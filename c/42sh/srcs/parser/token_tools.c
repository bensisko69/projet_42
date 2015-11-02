/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 19:18:06 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/12 19:34:49 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	add_token_to_array(void *p_token, size_t size, void *data)
{
	char	***array;
	t_token	*token;

	UNUSED(size);
	token = (t_token *)p_token;
	array = (char ***)data;
	**array = token->lexeme;
	++(*array);
}

char		**tokens_as_char_array(t_list *tokens)
{
	char	**array;
	char	**iarray;
	size_t	size;

	size = ft_lstsize(tokens);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	if (array)
	{
		iarray = array;
		ft_lstforeach(tokens, add_token_to_array, &iarray);
		*iarray = 0;
	}
	return (array);
}
