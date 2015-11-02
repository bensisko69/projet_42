/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:10:11 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/22 15:10:12 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_p(va_list list, int nbr)
{
	size_t			i;
	char		*str;
	int			size;
	int			b;

	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, size_t);
	ft_putnbr_base(i, "0123456789abcdef", 0, str);
	reverse(str);
	size = ft_strlen(str);
	if (nbr < size)
	{
		ft_putstr("0x");
		ft_putstr(str);
		return (ft_strlen(str) + 2);
	}
	else
	{
		nbr = nbr - size;
		b = nbr;
		while (nbr - 2 > 0)
		{
			write(1, " ", 1);
			nbr--;
		}
		ft_putstr("0x");
		ft_putstr(str);
		return (ft_strlen(str) + b);
	}
	return (0);
}