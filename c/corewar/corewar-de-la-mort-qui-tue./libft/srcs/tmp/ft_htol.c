/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/08 17:27:16 by mschuck           #+#    #+#             */
/*   Updated: 2014/08/08 17:27:18 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_htol(char *h)
{
	int		i;
	long	res;
	char	*k;

	if ((k = h) == NULL)
		return (0);
	if ((h = ft_strchr(h, 'x')))
		h++;
	else
		h = k;
	res = 0;
	while (*h && res >= 0)
	{
		i = (*h >= '0' && *h <= '9') ? *h - '0' : *h - 87;
		res = (res << 4) | i;
		h++;
	}
	return (res);
}
