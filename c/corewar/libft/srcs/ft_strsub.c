/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 16:01:54 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/21 19:21:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int		c;
	char				*str;

	c = 0;
	str = ft_memalloc(len + 1);
	if (str == NULL)
		return (NULL);
	while ((c != len) && s)
	{
		str[c] = s[start];
		c++;
		start++;
	}
	str[c] = '\0';
	return (str);
}
