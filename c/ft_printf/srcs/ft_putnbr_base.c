/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 15:53:38 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 15:53:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base(size_t nb, char *base, int i, char *str)
{
	int		len_base;

	len_base = ft_strlen(base);
	if (nb / len_base > 0)
	{
		ft_putnbr_base(nb / len_base, base, i + 1, str);
		str[i] = base[nb % len_base];
	}
	else
		str[i] = base[nb];
}

void	reverse(char *str)
{
	char	swap;	
	int		a;
	int		b;

	if (!str)
		return ;
	a = 0;
	b = ft_strlen(str) - 1;
	while (a < b)
	{
		swap = str[a];
		str[a] = str[b];
		str[b] = swap;
		a++;
		b--;
	}
}