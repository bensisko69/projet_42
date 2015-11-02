/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/21 12:58:55 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 21:07:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_l(char c, va_list list)
{
	static t_print	func_l[] = PRINT_L;
	unsigned int	a;

	a = 0;
	while (a < sizeof(func_l) / sizeof(t_print))
	{
		if (func_l[a].c == c)
			return (func_l[a].func(list));
		a++;
	}
	return (0);
}

int	print_ld(va_list list)
{
	long	p;

	p = va_arg(list, long);
	return (ft_putnbr_long(p, 1));
}

int	print_lx(va_list list)
{
	long	nb;

	nb = va_arg(list, long);
	return (ft_putnbr_base_long(nb, "0123456789abcdef", 0));
}

int	print_lo(va_list list)
{
	long	nb;

	nb = va_arg(list, long);
	return (ft_putnbr_base_long(nb, "01234567", 0));
}

int	print_lu(va_list list)
{
	unsigned long int	nb;

	nb = va_arg(list, unsigned long int);
	return (ft_putnbr_unsigned_long(nb, 0));
}
