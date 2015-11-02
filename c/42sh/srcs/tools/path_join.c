/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 06:20:32 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:19:10 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static char	*join_path_array(char **array, int sep_first)
{
	char	*str;
	size_t	array_size;
	size_t	total_len;
	size_t	len;
	size_t	i;

	array_size = char_array_size(array);
	total_len = char_array_map(array, (t_char_array_functor)ft_strlen);
	str = (char *)malloc(sizeof(char) * (total_len + array_size + sep_first));
	if (sep_first)
		str[0] = '/';
	i = sep_first;
	while (*array)
	{
		len = ft_strlen(*array);
		ft_strncpy(str + i, *array++, len);
		if (*array)
		{
			str[i + len] = '/';
			++i;
		}
		i += len;
	}
	str[i] = '\0';
	return (str);
}

static char	*join_path_arrays(char **head, char **tail, int sep_first)
{
	size_t	head_len;
	size_t	tail_len;
	char	**joined;
	size_t	i;
	char	*str;

	head_len = char_array_size(head);
	tail_len = char_array_size(tail);
	joined = (char **)malloc(sizeof(char *) * (head_len + tail_len + 1));
	i = 0;
	while (head && *head)
		joined[i++] = *head++;
	while (tail && *tail)
	{
		if (!ft_strcmp(*tail, ".."))
			joined[i -= (i > 0)] = 0;
		else if (ft_strcmp(*tail, "."))
			joined[i++] = *tail;
		++tail;
	}
	joined[i] = 0;
	str = join_path_array(joined, sep_first);
	free(joined);
	return (str);
}

char		*path_join(const char *head, const char *tail)
{
	char	**head_array;
	char	**tail_array;
	char	*joined;
	int		sep_first;

	sep_first = (head && *head == '/') || (tail && *tail == '/');
	head_array = ft_strsplit(head, '/');
	tail_array = ft_strsplit(tail, '/');
	joined = join_path_arrays(head_array, tail_array, sep_first);
	char_array_free(head_array);
	char_array_free(tail_array);
	return (joined);
}
