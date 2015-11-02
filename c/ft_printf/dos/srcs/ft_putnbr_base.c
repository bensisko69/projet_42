/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 18:57:30 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 22:58:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putnbr_base(size_t nb, char *base, int l)
{
	char	c;
	int		len_base;

	len_base = ft_strlen(base);
	if (nb / len_base > 0)
	{
		l = ft_putnbr_base(nb / len_base, base, l);
		l = ft_putnbr_base(nb % len_base, base, l);
	}
	else
	{
		c = base[nb];
		write(1, &c, 1);
		l++;
	}
	return (l);
}
