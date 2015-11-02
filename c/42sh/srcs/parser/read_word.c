/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 17:23:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/03 19:03:50 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	is_word_char(char c)
{
	return (ft_isalnum(c) || ft_strchr(WORD_CHARS, c));
}

static int	extract_until(char **dest, char *src, char c, size_t *len)
{
	char	*isrc;

	isrc = src;
	while (*isrc != c)
	{
		**dest = *isrc++;
		++(*dest);
		--(*len);
	}
	--(*len);
	return (isrc - src + 1);
}

static int	extract_word(t_token *token, char *start, size_t len, size_t ignore)
{
	char	*word;
	char	*iword;

	if (len == 0)
		return (0);
	word = (char *)malloc(sizeof(char) * (len - ignore + 1));
	word[len - ignore] = '\0';
	iword = word;
	while (len)
	{
		if (*start == '"' || *start == '\'')
			start += extract_until(&iword, start + 1, *start, &len);
		else if (*start == '\\')
		{
			*iword++ = *(++start);
			--len;
		}
		else
			*iword++ = *start;
		++start;
		--len;
	}
	token->type = WORD;
	token->lexeme = word;
	return (1);
}

static int	goto_next(char **stream, char c)
{
	++(*stream);
	while (**stream && **stream != c)
		++(*stream);
	return (**stream);
}

int			read_word(char **stream, t_token *token)
{
	char	*save;
	int		ignore_count;

	save = *stream;
	ignore_count = 0;
	while (**stream && is_word_char(**stream))
	{
		if (**stream == '"' || **stream == '\'')
		{
			if (!goto_next(stream, **stream))
				return (0);
			ignore_count += 2;
		}
		if (**stream == '\\')
		{
			++(*stream);
			++ignore_count;
			if (!**stream)
				return (0);
		}
		++(*stream);
	}
	return (extract_word(token, save, *stream - save, ignore_count));
}
