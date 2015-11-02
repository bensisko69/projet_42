/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 11:54:48 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/22 11:54:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_neg(char *str, int nbr, int size, int neg)
{
	int	b;

	if (nbr == 0 && neg != 1)
		ft_putstr(str);
	else if (nbr == 0 && neg == 1)
	{
		ft_putchar('-');
		ft_putstr(str);
		return (ft_strlen(str) + 1);
	}
	else
	{
		nbr = nbr - size;
		b = nbr;
		while (nbr - 1 > 0)
		{
			write(1, " ", 1);
			nbr--;
		}
		ft_putchar('-');
		ft_putstr(str);
		return ((b + ft_strlen(str)));
	}
	return (ft_strlen(str));
}

static int	print_pos(char *str, int nbr, int size, int neg)
{
	int	b;

	if (nbr == 0 && neg == 0)
		ft_putstr(str);
	else
	{
		nbr = nbr - size;
		b = nbr;
		while (nbr > 0)
		{
			write(1, " ", 1);
			nbr--;
		}
		ft_putstr(str);
		return ((b + ft_strlen(str)));
	}
	return (ft_strlen(str));
}

static int print(char *str, int nbr, int size, int neg)
{
	if (neg == 1)
		return (print_neg(str, nbr, size, neg));
	else
		return (print_pos(str, nbr, size, neg));
}

int	print_d_l(va_list list, int nbr)
{
	long int		i;
	int				neg;
	char			*str;
	int				size;

	neg = 0;
	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, long int);
	if(i < 0)
	{
		neg = 1;
		if (i <= -9223372036854775807)
			return (print("9223372036854775808", nbr, 0, neg));
		ft_putnbr_base(-i, "0123456789", 0, str);
	}
	else
	{
		if (i >= 9223372036854775807)
			return (print("9223372036854775807", nbr, 0, neg));
		ft_putnbr_base(i, "0123456789", 0, str);
	}
	reverse(str);
	size = ft_strlen(str);
	return (print(str, nbr, size, neg));
}
