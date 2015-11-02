/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:21:34 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 14:21:34 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_s(va_list list, int nbr)
{
	char	*str;
	int		size;
	int		a;

	str = va_arg(list, char *);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = ft_strlen(str);
	a = nbr - (size);
	if (nbr < size)
	{
		write(1, str, size);
		return (size);
	}
	else
	{
		while (a > 0)
		{
			write(1, " ", 1);
			a--;
		}
		write(1, str, size);
		return (size + (nbr - size));
	}
	return (size + (nbr - size));
}