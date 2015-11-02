/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:18:03 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:31:36 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putnbr_printf(int n)
{
	int		i;

	i = 1;
	if (n == -2147483648)
	{
		ft_putstr_printf("-2147483648");
		i = 11;
		return (i);
	}
	if (n < 0)
	{
		i++;
		n = -n;
		ft_putchar_printf('-');
	}
	if (n > 10)
	{
		i += ft_putnbr_printf(n / 10);
		ft_putnbr_printf(n % 10);
	}
	else
		ft_putchar_printf(48 + n);
	return (i);
}
