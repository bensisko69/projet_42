/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_C_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:24:32 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/28 15:24:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_c_maj(va_list list, int nbr)
{
	wchar_t	c;
	int		size;

	size = nbr;
	c = va_arg(list, wchar_t);
	if (c >= 0 && c <= 250)
	{
		while (nbr - 1 > 0)
		{
			write(1, " ", 1);
			nbr--;
		}
		write(1, &c, 1);
		return (size + 1);
	}
	else
		return (0);
}