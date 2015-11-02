/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 10:41:43 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/09/19 12:07:01 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char		*s12;
	const char		*s22;
	size_t			i;

	s12 = s1;
	s22 = s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i != n)
	{
		if (s12[i] != s22[i])
			return ((t_uchar)s12[i] - (t_uchar)s22[i]);
		i++;
	}
	return (0);
}
