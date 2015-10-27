/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 21:47:01 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/27 22:47:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	parse(char *str)
{
	int	a;

	a = 0;
	while (str[a])
	{
		if (str[a] >= 'G' && str[a] <= 'Z')
		{
			ft_putendl_fd("Map error", 1);
			return (1);
		}
		else if ((str[a] >= 'g' && str[a] <= 'w')
				&& (str[a] >= 'y' && str[a] <= 'z'))
		{
			ft_putendl_fd("Map error", 1);
			return (1);
		}
		a++;
	}
	return (0);
}
