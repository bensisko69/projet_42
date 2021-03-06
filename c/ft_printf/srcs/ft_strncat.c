/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:29:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/23 17:39:58 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	c;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = ft_strlen(s1);
	i = 0;
	while (i < n && s2[i] != '\0')
	{
		s1[i + c] = s2[i];
		i++;
	}
	s1[c + i] = '\0';
	return (s1);
}
