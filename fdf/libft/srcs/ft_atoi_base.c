/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 14:41:20 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/13 16:51:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int n, int e)
{
	if (e == 0)
		return (1);
	if (e == 1)
		return (n);
	return (n * ft_power(n, e - 1));
}

static int	ft_ignore(char m)
{
	return (m == '\n'
	|| m == '\v'
	|| m == '\t'
	|| m == '\r'
	|| m == '\f'
	|| m == ' ');
}

static char	*convers(char *str)
{
	int		a;

	a = 0;
	if (*str == '0')
	{
		str++;
		if (*str == 'x' || *str == 'X')
			str++;
	}
	while (str[a])
	{
		if (str[a] >= 'A' && str[a] <= 'F')
			str[a] += 32;
		a++;
	}
	return (str);
}

int			ft_atoi_base(char *str, char *base)
{
	int		i;
	int		a;
	int		color;
	int		power;

	a = 0;
	color = 0;
	power = 5;
	i = 0;
	if (str == 0)
		return (0);
	while (ft_ignore(*str))
		str++;
	str = convers(str);
	while (str[a])
	{
		while (str[a] != base[i] && str[a] && base[i])
			i++;
		a++;
		color += i * ft_power(ft_strlen(base), power);
		i = 0;
		power--;
	}
	return (color);
}
