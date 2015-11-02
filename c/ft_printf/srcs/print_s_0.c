/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 14:39:25 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 14:39:26 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_s_0(va_list list, int nbr)
{
	char	*str;
	int		size;
	int		a;

	str = va_arg(list, char *);
	size = ft_strlen(str);
	a = nbr - size;
	if (nbr < size)
	{
		write(1, str, size);
		return (size);
	}
	else
	{
		while (a > 0)
		{
			write(1, "0", 1);
			a--;
		}
		write(1, str, size);
		return ((nbr - size) + size);
	}
	return (0);
}