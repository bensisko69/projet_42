/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 17:04:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/29 14:33:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_map *p1, t_map *p2, t_env *e)
{
	float	c;
	float	x_inc;
	float	x;
	float	y;

	if (p1 && p2)
	{
		c = (p2->y - p1->y) / (p2->x - p1->x);
		ft_putnbr(c);
		ft_putchar('\n');
		x_inc = (p2->x > p1->x ? 0.2 : -0.2);
		x = p1->x;
		y = p1->y;
		while (((x < p2->x && x_inc > 0) || (x > p2->x && x_inc < 0))
				&& y != p2->y)
		{
			mlx_pixel_put(e->mlx, e->win, x, y, p1->color);
			x += x_inc;
			y += c * x_inc;
			p1->color += (p2->z + p1->z) * 20;
		}
	}
}

int		size_line(char **str)
{
	int	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}
