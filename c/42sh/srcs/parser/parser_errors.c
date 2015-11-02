/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 14:30:26 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/12 16:30:09 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*last_lexeme(t_list *tokens)
{
	if (tokens)
	{
		while (tokens->next)
			tokens = tokens->next;
		return (token_value(tokens, 1));
	}
	return (0);
}

static void	error(t_list *tokens, const char *prefix, const char *default_info)
{
	char	*lexeme;
	char	*info;
	size_t	len;

	lexeme = last_lexeme(tokens);
	if (lexeme)
	{
		len = ft_strlen(lexeme);
		info = (char *)malloc(sizeof(char) * (len + 3));
		ft_strncpy(info, "`", 1);
		ft_strncpy(info + 1, lexeme, len);
		ft_strcpy(info + len + 1, "'");
		shell_error(prefix, info);
		free(info);
	}
	else
		shell_error(prefix, default_info);
}

void		syntax_error(t_list *tokens)
{
	error(tokens, ERR_SYNTAX, ERR_SYNTAX_START);
}

void		parse_error(t_list *tokens)
{
	error(tokens, ERR_PARSE, ERR_PARSE_END);
}
