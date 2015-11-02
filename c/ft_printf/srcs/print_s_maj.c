/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_maj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 15:36:20 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/28 15:36:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_s(va_list list, int nbr)
{
	char	*str;
	int		size;
	int		a;

	str = va_arg(list, char *);
	size = ft_strlen(str);
	a = nbr - (size);
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
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
		return (size + a);
	}
	return (0);
}