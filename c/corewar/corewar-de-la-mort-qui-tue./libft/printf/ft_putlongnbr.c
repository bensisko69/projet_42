/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:33:50 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:35:32 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putlongnbr(long int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = -n;
		ft_putchar_printf('-');
	}
	if (n >= 10)
	{
		i += ft_putlongnbr(n / 10);
		ft_putlongnbr(n % 10);
	}
	else
		ft_putchar_printf(48 + n);
	return (i);
}
