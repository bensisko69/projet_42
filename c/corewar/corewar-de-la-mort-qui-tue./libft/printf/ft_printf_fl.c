/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 18:25:18 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:30:44 by mbudin           ###   ########.fr       */
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
	if (str)
		return (ft_putstr_printf(str));
	return (ft_putstr_printf("(null)"));
}

int		ft_printf_d(va_list var)
{
	int		i;

	i = va_arg(var, int);
	return (ft_putnbr_printf(i));
}

int		ft_printf_p(va_list var)
{
	void	*str;

	str = va_arg(var, void *);
	ft_putstr_printf("0x");
	return (ft_putnbr_base_p((size_t)str, "0123456789abcdef") + 2);
}

int		ft_printf_pc(va_list var)
{
	(void)var;
	return (ft_putchar_printf('%'));
}
