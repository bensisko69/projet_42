/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/16 10:42:36 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/16 10:47:44 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_long(long nb, int l)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		l++;
		l = ft_putnbr_long(nb / 10, l);
		l = ft_putnbr_long(nb % 10, l);
	}
	else
		ft_putchar(48 + nb);
	return (l);
}
