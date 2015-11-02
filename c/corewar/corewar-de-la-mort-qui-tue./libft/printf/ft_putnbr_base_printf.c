/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/07/10 14:57:23 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:41:58 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		check_base(char *base)
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

unsigned int	ft_putnbr_base_p(size_t nbr, char *base)
{
	char	c;
	int		len_base;
	int		i;

	i = 1;
	len_base = ft_strlen_printf(base);
	if (check_base(base) == 1)
	{
		if (nbr / len_base > 0)
		{
			i += ft_putnbr_base_p(nbr / len_base, base);
			ft_putnbr_base_p(nbr % len_base, base);
		}
		else
		{
			c = base[nbr];
			write(1, &c, 1);
		}
		return (i);
	}
	else
		return (ft_putnbr_printf(nbr));
}

unsigned int	ft_putnbr_base_printf(unsigned int nbr, char *base)
{
	char	c;
	int		len_base;
	int		i;

	i = 1;
	len_base = ft_strlen_printf(base);
	if (check_base(base) == 1)
	{
		if (nbr / len_base > 0)
		{
			i += ft_putnbr_base_printf(nbr / len_base, base);
			ft_putnbr_base_printf(nbr % len_base, base);
		}
		else
		{
			c = base[nbr];
			write(1, &c, 1);
		}
		return (i);
	}
	else
		return (ft_putnbr_printf(nbr));
}
