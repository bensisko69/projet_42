/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 21:05:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/20 21:05:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c(va_list list, int nbr)
{
	char	c;
	int		size;

	size = nbr;
	c = va_arg(list, int);
	while (nbr - 1 > 0)
	{
		write(1, " ", 1);
		nbr--;
	}
	write(1, &c, 1);
	return (size + 1);
}
