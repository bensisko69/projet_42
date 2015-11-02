/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:00:34 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 23:03:55 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list list)
{
	unsigned int	nb;

	nb = va_arg(list, unsigned int);
	return (ft_putnbr_unsigned(nb, 1));
}

int	print_o(va_list list)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(list, unsigned int);
	return (ft_putnbr_base(nb, "01234567", len));
}

int	print_b(va_list list)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(list, int);
	return (ft_putnbr_base(nb, "01", len));
}

int	print_x_maj(va_list list)
{
	unsigned int	nb;
	int				len;

	len = 0;
	nb = va_arg(list, unsigned int);
	return (ft_putnbr_base(nb, "0123456789ABCDEF", len));
}

int	print_po(va_list list)
{
	(void)list;
	return (ft_putchar('%'));
}
