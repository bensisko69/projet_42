/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 17:42:59 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:31:06 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf_o(va_list var)
{
	unsigned int		i;

	i = va_arg(var, unsigned int);
	return (ft_putnbr_base_printf(i, "01234567"));
}

int		ft_printf_x(va_list var)
{
	unsigned int		i;

	i = va_arg(var, unsigned int);
	return (ft_putnbr_base_printf(i, "0123456789abcdef"));
}

int		ft_printf_mx(va_list var)
{
	unsigned int		i;

	i = va_arg(var, unsigned int);
	return (ft_putnbr_base_printf(i, "0123456789ABCDEF"));
}

int		ft_printf_b(va_list var)
{
	unsigned int		i;

	i = va_arg(var, unsigned int);
	return (ft_putnbr_base_printf(i, "01"));
}

int		ft_printf_u(va_list var)
{
	unsigned int		i;

	i = va_arg(var, unsigned int);
	return (ft_putnbr_base_printf(i, "00"));
}
