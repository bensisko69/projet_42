/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:24:48 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/02/04 16:24:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int print(char *str, int nbr, int neg)
{
	if (neg == 1)
		return (print_neg2(str, nbr, ' '));
	else
		return (print_pos2(str, nbr, ' '));
}

int	print_d_ps(va_list list, int nbr)
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
	if (ft_atoi(str) < -2147483647)
		return (print("2147483648", nbr, neg));
	size = print(str, nbr, neg);
	return (size);
}