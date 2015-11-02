/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunslongint_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/25 18:10:02 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:36:19 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int				check_base(char *base)
{
	int		i;

	i = 0;
	if (ft_strlen_printf(base) == 0 || ft_strlen_printf(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == base[i + 1])
			return (0);
		i++;
	}
	return (1);
}

unsigned long int		ft_putunslongint_base(unsigned long int n, char *base)
{
	char	c;
	int		len_base;
	int		i;

	i = 1;
	len_base = ft_strlen_printf(base);
	if (check_base(base) == 1)
	{
		if (n / len_base > 0)
		{
			i += ft_putunslongint_base(n / len_base, base);
			ft_putunslongint_base(n % len_base, base);
		}
		else
		{
			c = base[n];
			write(1, &c, 1);
		}
		return (i);
	}
	else
		return (ft_putlongnbr(n));
}
