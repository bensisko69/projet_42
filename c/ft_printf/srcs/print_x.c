/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 16:43:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 16:43:58 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_x(va_list list, int nbr)
{
	size_t		i;
	char	*str;
	int		size;

	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, size_t);
	ft_putnbr_base(i, "0123456789abcdef", 0, str);
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