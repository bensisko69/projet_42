/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 18:16:36 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:39:10 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf_cr(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	ft_putstr_color(RED);
	return (ft_putstr_printf(str));
}

int		ft_printf_cv(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	ft_putstr_color(GREEN);
	return (ft_putstr_printf(str));
}

int		ft_printf_cj(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	ft_putstr_color(YELLOW);
	return (ft_putstr_printf(str));
}

int		ft_printf_cc(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	ft_putstr_color(CYAN);
	return (ft_putstr_printf(str));
}

int		ft_printf_cp(va_list var)
{
	char	*str;

	str = va_arg(var, char *);
	ft_putstr_color(PURPLE);
	return (ft_putstr_printf(str));
}
