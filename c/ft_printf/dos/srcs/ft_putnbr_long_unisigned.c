/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_long_unisigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 14:15:13 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/22 16:14:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned_long(unsigned long int nb, int l)
{
	if (nb >= 10)
	{
		l = ft_putnbr_unsigned_long(nb / 10, l);
		l = ft_putnbr_unsigned_long(nb % 10, l);
	}
	else
	{
		l++;
		ft_putchar(48 + nb);
	}
	return (l);
}
