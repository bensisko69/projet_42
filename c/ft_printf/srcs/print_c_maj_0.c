/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_maj_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:33:17 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/28 15:33:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c_maj_0(va_list list, int nbr)
{
	wchar_t	c;
	int		size;

	size = nbr;
	c = va_arg(list, wchar_t);
	if (c >= 0 && c <= 250)
	{
		while (nbr - 1 > 0)
		{
			write(1, "0", 1);
			nbr--;
		}
		write(1, &c, 1);
		return (size + 1);
	}
	else
		return (0);
}