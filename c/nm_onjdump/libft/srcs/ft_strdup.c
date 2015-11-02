/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 11:21:29 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 17:33:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s, char *letter)
{
	char		*dup;
	int			c;

	c = (ft_strlen(s) + 2);
	dup = (char*)malloc((c + 1) * sizeof(char));
	if (dup != 0)
		ft_memcpy(dup, s, c + 1, letter);
	return (dup);
}
