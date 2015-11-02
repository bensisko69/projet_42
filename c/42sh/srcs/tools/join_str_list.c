/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_str_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 13:32:28 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:08:24 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

static size_t	str_list_len(t_list *list)
{
	size_t		len;

	len = 0;
	while (list)
	{
		len += ft_strlen((char *)list->content) + 1;
		list = list->next;
	}
	return (len - 1);
}

char			*join_str_list(t_list *str_list, char c)
{
	char		*joined;
	size_t		len;
	size_t		i;

	len = str_list_len(str_list);
	joined = (char *)malloc(sizeof(char) * (len + 1));
	joined[len] = 0;
	i = 0;
	while (str_list)
	{
		len = ft_strlen((char *)str_list->content);
		ft_strncpy(joined + i, (char *)str_list->content, len);
		if (str_list->next)
			joined[i + len] = c;
		i += len + 1;
		str_list = str_list->next;
	}
	return (joined);
}
