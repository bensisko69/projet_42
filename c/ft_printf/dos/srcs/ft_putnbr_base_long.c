/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 14:30:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/21 14:30:04 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbr_base_long(long nb, char *base, int l)
{
	char	c;
	int		len_base;

	len_base = ft_strlen(base);
	if (nb / len_base > 0)
	{
		l = ft_putnbr_base_long(nb / len_base, base, l);
		l = ft_putnbr_base_long(nb % len_base, base, l);
	}
	else
	{
		if (nb >= 0)
		{
			c = base[nb];
			write(1, &c, 1);
			l++;
		}
	}
	return (l);
}
