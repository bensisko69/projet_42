/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_X_MAJ_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 21:41:05 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 21:41:05 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_X_MAJ_0(va_list list, int nbr)
{
	size_t	i;
	char	*str;
	int		size;
	int		b;

	b = nbr;
	str = (char *)ft_memalloc(sizeof(char) * 100);
	i = va_arg(list, int);
	ft_putnbr_base(i, "0123456789ABCDEF", 0, str);
	reverse(str);
	size = ft_strlen(str);
	if (nbr < size)
		ft_putstr(str);
	else
	{
		nbr = nbr - size;
		while (nbr > 0)
		{
			write(1, "0", 1);
			nbr--;
		}
		ft_putstr(str);
	}
	return (b);
}