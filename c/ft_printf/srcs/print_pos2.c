/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pos2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 13:16:55 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/02/06 13:16:57 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_pos2(char *str, int nbr, char c)
{
	int	b;

	if (nbr == 0)
	{
		write(1, "+", 1);
		ft_putstr(str);
	}
	else
	{
		nbr = nbr - ft_strlen(str);
		b = nbr;
		while ((nbr - 1) > 0)
		{
			write(1, &c, 1);
			nbr--;
		}
		write(1, "+", 1);
		ft_putstr(str);
		if (b > 0)
			return ((b + ft_strlen(str)));
	}
	return (ft_strlen(str) + 1);
}

int		print_neg2(char *str, int nbr, char c)
{
	int	b;

	if (nbr == 0)
	{
		ft_putchar('-');
		ft_putstr(str);
	}
	else
	{
		nbr = nbr - ft_strlen(str);
		b = nbr;
		while ((nbr - 1) > 0)
		{
			write(1, &c, 1);
			nbr--;
		}
		write(1, "-", 1);
		ft_putstr(str);
		if (b > 0)
			return ((b + ft_strlen(str)));
	}
	return (ft_strlen(str) + 1);
}