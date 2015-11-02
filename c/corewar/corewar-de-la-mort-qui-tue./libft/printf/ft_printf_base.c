/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/22 17:33:50 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:59:53 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf_c(va_list var)
{
	char	c;

	c = va_arg(var, int);
	return (ft_putchar_printf(c));
}

int		ft_printf_s(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	return (ft_putstr_printf(str));
}

int		ft_printf_d(va_list var)
{
	int		i;

	i = va_arg(var, int);
	return (ft_putnbr_printf(i));
}
