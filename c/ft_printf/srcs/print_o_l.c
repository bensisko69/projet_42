/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_l.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 15:19:40 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/22 15:19:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_o_l(va_list list, int nbr)
{
	long int	i;
	char		*str;
	int			size;

	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, long int);
	ft_putnbr_base_long(i, "01234567", 0, str);
	reverse(str);
	size = ft_strlen(str);
	if (nbr < size)
		ft_putstr(str);
	else
	{
		nbr = nbr - size;
		while (nbr > 0)
		{
			write(1, " ", 1);
			nbr--;
		}
		ft_putstr(str);
	}
	return (ft_strlen(str));
}