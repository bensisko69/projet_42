/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/31 15:09:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 15:09:39 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_error(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

static int	check_double(char **tab)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (tab[i])
	{
		while (tab[j])
		{
			if (i == j)
			{
				j++;
				continue ;
			}
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

int			check(char **tab)
{
	int i;

	i = 1;
	if (strcmp(tab[1], "-v") == 0)
		i = 2;
	while (tab[i])
	{
		if (ft_error(tab[i]) == 1)
		{
			ft_putstr_fd("ERROR, NBR PLEASE", 2);
			return (1);
		}
		i++;
	}
	if (check_double(tab) == 1)
	{
		ft_putstr_fd("ERROR, DOUBLE", 2);
		return (1);
	}
	return (0);
}
