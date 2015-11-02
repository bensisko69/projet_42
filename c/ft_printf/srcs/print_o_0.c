/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 21:33:38 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 21:33:39 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_neg(char *str, int nbr, int size, int neg)
{
	if (nbr == 0 && neg != 1)
		ft_putstr(str);
	else if (nbr == 0 && neg == 1)
	{
		ft_putchar('-');
		ft_putstr(str);
	}
	else
	{
		nbr = nbr - size;
		while (nbr - 1 > 0)
		{
			write(1, "0", 1);
			nbr--;
		}
		ft_putchar('-');
		ft_putstr(str);
	}
}

static void	print_pos(char *str, int nbr, int size, int neg)
{
	if (nbr == 0 && neg != 1)
		ft_putstr(str);
	else if (nbr == 0 && neg == 1)
	{
		ft_putchar('-');
		ft_putstr(str);
	}
	else
	{
		nbr = nbr - size;
		while (nbr> 0)
		{
			write(1, "0", 1);
			nbr--;
		}
		ft_putstr(str);
	}
}

static void print(char *str, int nbr, int size, int neg)
{
	if (neg == 1)
		print_neg(str, nbr, size, neg);
	else
		print_pos(str, nbr, size, neg);
}

int	print_o_0(va_list list, int nbr)
{
	size_t		i;
	int			neg;
	char		*str;
	int			size;
	int			b;

	neg = 0;
	b = nbr;
	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, size_t);
	ft_putnbr_base(i, "01234567", 0, str);
	reverse(str);
	size = ft_strlen(str);
	print(str, nbr, size, neg);
	return (b);
}