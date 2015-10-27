/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/20 13:33:04 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/29 15:30:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		len_line(t_map **map)
{
	int	a;

	a = 0;
	while (map[a])
		a++;
	return (a);
}

static void		print_map(t_env *e)
{
	int	a;
	int	b;

	a = 0;
	while (e->map[a])
	{
		b = 0;
		while (b < len_line(e->map[a]))
		{
			if (b < len_line(e->map[a]))
				draw_line(e->map[a][b], e->map[a][b + 1], e);
			if (e->map[a + 1] && b < len_line(e->map[a + 1]))
				draw_line(e->map[a][b], e->map[a + 1][b], e);
			b++;
		}
		a++;
	}
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		(void)e;
		exit (1);
	}
	return (0);
}

int				expose_hook(t_env *e)
{
	print_map(e);
	return (0);
}

void			display(t_map ***map)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, SIZE1, SIZE2, "FDF");
	e.map = map;
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
}
