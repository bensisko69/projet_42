/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:53:35 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/22 11:53:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_long(long int nb, char *base, int i, char *str)
{
	long int		len_base;

	len_base = (long)ft_strlen(base);
	if (nb / len_base > 0)
	{
		ft_putnbr_base_long(nb / len_base, base, i + 1, str);
		str[i] = base[nb % len_base];
	}
	else
		str[i] = base[nb];
}