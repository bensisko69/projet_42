/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:15:53 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 16:15:53 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_neg(char *str, int nbr, int size, int neg)
{
	int		b;
	size_t	nbr2;

	nbr2 = nbr;
	if (nbr == 0 && neg == 1)
	{
		ft_putchar('-');
		ft_putstr(str);
		return (ft_strlen(str) + 1);
	}
	else if (nbr2 > ft_strlen(str))
	{
		nbr = nbr - size;
		b = nbr;
		ft_putchar('-');
		while (nbr - 1 > 0)
		{
			write(1, "0", 1);
			nbr--;
		}
		ft_putstr(str);
		return ((b + ft_strlen(str)));
	}
	ft_putchar('-');
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	print_pos(char *str, int nbr, int size, int neg)
{
	int		b;
	size_t	nbr2;

	nbr2 = nbr - size;
	if (nbr == 0 && neg == 1)
	{
		ft_putchar('-');
		ft_putstr(str);
		return (ft_strlen(str) + 1);
	}
	else if (nbr2 > ft_strlen(str))
	{
		nbr = nbr - size;
		b = nbr;
		while (nbr2 > 0)
		{
			write(1, "0", 1);
			nbr2--;
		}
		ft_putstr(str);
		return ((b + ft_strlen(str)));
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

static int print(char *str, int nbr, int size, int neg)
{
	if (neg == 1)
		return (print_neg(str, nbr, size, neg));
	else
		return (print_pos(str, nbr, size, neg));
	return (0);
}

int	print_d_0(va_list list, int nbr)
{
	int		i;
	int		neg;
	char	*str;
	int		size;

	neg = 0;
	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, int);
	if(i < 0)
	{
		ft_putnbr_base(-i, "0123456789", 0, str);
		neg = 1;
	}
	else
		ft_putnbr_base(i, "0123456789", 0, str);
	reverse(str);
	size = ft_strlen(str);
	if (ft_atoi(str) < -2147483647)
		return (print("2147483648", nbr, size, neg));
	return (print(str, nbr, size, neg));
}
