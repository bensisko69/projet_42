/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 14:30:33 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/21 14:30:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb, int l)
{
	if (nb >= 10)
	{
		l++;
		l = ft_putnbr_unsigned(nb / 10, l);
		l = ft_putnbr_unsigned(nb % 10, l);
	}
	else
		ft_putchar(48 + nb);
	return (l);
}
