/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:39:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 16:50:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n, char *letter)
{
	char		*dest1;
	const char	*src1;
	size_t		i;
	size_t		i2;

	i2 = 0;
	i = 2;
	dest1 = dest;
	src1 = src;
	dest1[0] = letter[0];
	dest1[1] = letter[1];
	while (i < n)
	{
		dest1[i] = src1[i2];
		i++;
		i2++;
	}
	return (dest1);
}
