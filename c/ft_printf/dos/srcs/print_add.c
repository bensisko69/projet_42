/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/06 22:32:54 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/16 12:19:30 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_adress(void const *p)
{
	unsigned long			adr;
	char const				*base;
	char					res[9];
	int						i;

	adr = (unsigned long)p;
	base = "0123456789abcdef";
	i = 8;
	while ((adr / 16) > 0 || i >= 8)
	{
		res[i] = base[(adr % 16)];
		adr /= 16;
		i--;
	}
	res[i] = base[(adr % 16)];
	ft_putchar ('0');
	ft_putchar ('x');
	while (i < 9)
	{
		ft_putchar (res[i]);
		i++;
	}
	return ((ft_strlen(res)));
}
