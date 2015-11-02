/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/06 22:32:34 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 23:04:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(va_list list)
{
	char	*str;

	str = va_arg(list, char*);
	return (ft_putstr(str));
}

int	print_d(va_list list)
{
	int		nb;

	nb = va_arg(list, int);
	return (ft_putnbr(nb, 1));
}

int	print_c(va_list list)
{
	char	c;

	c = va_arg(list, int);
	return (ft_putchar(c));
}

int	print_p(va_list list)
{
	void	*p;

	p = va_arg(list, void*);
	return (put_adress(p));
}

int	print_x(va_list list)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(list, unsigned int);
	return (ft_putnbr_base((size_t)nb, "0123456789abcdef", len));
}
