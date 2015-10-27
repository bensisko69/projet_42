/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 15:33:33 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/13 16:50:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			convers(t_map ***map)
{
	int	a;
	int	b;

	a = 0;
	while (map[a])
	{
		b = 0;
		while (map[a][b])
		{
			map[a][b]->x = CTE1 * map[a][b]->x - CTE2 * -map[a][b]->y +
							SIZE_PIXELX;
			map[a][b]->y = map[a][b]->z + CTE1 / 2 * map[a][b]->x + CTE2 / 2 *
							-map[a][b]->y + SIZE_PIXELY;
			b++;
		}
		a++;
	}
}

int				color(char *str)
{
	char	*color;
	int		col;

	col = 0;
	while (*str && *str != ',')
		str++;
	if (*str == ',')
	{
		str++;
		color = ft_strdup(str);
		col = ft_atoi_base(color, "0123456789abcdef");
		free(color);
		if (col != 0)
			return (col);
	}
	return (RED);
}
