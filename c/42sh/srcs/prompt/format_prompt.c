/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 20:04:09 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 22:43:17 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "parser.h"

static size_t	total_size(t_list *tokens)
{
	size_t		total;
	t_token		*token;

	total = 0;
	while (tokens)
	{
		token = get_token(&tokens);
		if (token->type == CHARS)
			total += ft_strlen(token->lexeme);
		else
			total += ft_strlen(token->lexeme) + COLOR_STR_SIZE;
		tokens = tokens->next;
	}
	return (total);
}

static void		add_color(t_token *token, char *str, size_t len)
{
	if (token->type == FG_COLOR)
		NCPY(str, FG_COLOR_PREFIX);
	else
		NCPY(str, BG_COLOR_PREFIX);
	ft_strncpy(str + COLOR_PREFIX_SIZE, token->lexeme, len);
	NCPY(str + COLOR_PREFIX_SIZE + len, COLOR_SUFFIX);
}

static char		*parse_prompt_tokens(t_list *tokens)
{
	size_t		size;
	char		*str;
	size_t		i;
	size_t		len;
	t_token		*token;

	size = total_size(tokens);
	str = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (tokens)
	{
		token = get_token(&tokens);
		len = ft_strlen(token->lexeme);
		if (token->type == CHARS)
			ft_strncpy(str + i, token->lexeme, len);
		else
		{
			add_color(token, str + i, len);
			i += COLOR_STR_SIZE;
		}
		i += len;
		tokens = tokens->next;
	}
	str[i] = '\0';
	return (str);
}

char			*format_prompt(t_context *context, const char *format)
{
	t_list		*tokens;
	char		*formatted;

	tokens = tokenize_prompt(context, (char *)format);
	if (!tokens)
		return (format_prompt(context, DEFAULT_PROMPT));
	formatted = parse_prompt_tokens(tokens);
	ft_lstdel(&tokens, free_token);
	return (formatted);
}
