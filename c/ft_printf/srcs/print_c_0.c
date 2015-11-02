/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 11:08:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 11:08:31 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c_0(va_list list, int nbr)
{
	char	c;
	int		size;

	size = nbr;
	c = va_arg(list, int);
	while (nbr - 1 > 0)
	{
		write(1, "0", 1);
		nbr--;
	}
	write(1, &c, 1);
	return (size);
}