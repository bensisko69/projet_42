/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 22:51:10 by ibuchwal          #+#    #+#             */
/*   Updated: 2014/03/16 23:11:30 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char		*str_replace(const char *str, const char *find, const char *replace)
{
	char	*new_str;
	char	*change;
	size_t	len_s;
	size_t	len_f;
	size_t	len_r;

	change = ft_strstr(str, find);
	if (change == 0)
		return (ft_strdup(str));
	len_s = ft_strlen(str);
	len_f = ft_strlen(find);
	len_r = ft_strlen(replace);
	new_str = (char *)malloc(sizeof(char) * (len_s + len_f + len_r + 1));
	ft_strncpy(new_str, str, change - str);
	ft_strncpy(new_str + (change - str), replace, len_r);
	ft_strcpy(new_str + (change - str) + len_r, str + len_f + (change - str));
	return (new_str);
}
