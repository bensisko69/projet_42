/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 08:48:02 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/13 16:51:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ignore(char m)
{
	return (m == '\n'
	|| m == '\v'
	|| m == '\t'
	|| m == '\r'
	|| m == '\f'
	|| m == ' ');
}

int			ft_atoi(const char *nptr)
{
	int	c;
	int	i;

	i = 0;
	if (nptr == 0)
		return (0);
	while (ft_ignore(*nptr))
		nptr++;
	c = (nptr[0] == '-' || nptr[0] == '+');
	while (ft_isdigit(nptr[c]))
	{
		i = i * 10 + nptr[c] - '0';
		c = c + 1;
	}
	if (nptr[0] == '-')
		return (-i);
	return (i);
}
