/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_l.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:33:50 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/26 17:24:55 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf_ld(va_list var)
{
	int	i;

	i = va_arg(var, long int);
	return (ft_putunslongint_base(i, "00"));
}

int		ft_printf_lo(va_list var)
{
	unsigned long int	i;

	i = va_arg(var, unsigned long int);
	return (ft_putunslongint_base(i, "01234567"));
}

int		ft_printf_lx(va_list var)
{
	unsigned long int	i;

	i = va_arg(var, unsigned long int);
	return (ft_putunslongint_base(i, "0123456789abcdef"));
}

int		ft_printf_lmx(va_list var)
{
	unsigned long int	i;

	i = va_arg(var, unsigned long int);
	return (ft_putunslongint_base(i, "0123456789ABCDEF"));
}
