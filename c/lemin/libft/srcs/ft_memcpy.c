/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:39:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/27 16:01:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*str1;
	const char	*str2;

	str1 = (char *)s1;
	str2 = (const char *)s2;
	while (n--)
		str1[n] = str2[n];
	return (s1);
}
