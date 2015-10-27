/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 12:28:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/29 15:39:27 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE_PIXEL 30
# define RED 0xFF0000
# define WHITE 0xFCFAE1
# define GREEN 0xAEEE00
# define CTE1 0.7
# define CTE2 0.8
# define SIZE_PIXELY 900
# define SIZE_PIXELX 300
# define SIZE1 2000
# define SIZE2 2000
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>

typedef struct		s_map
{
	float			x;
	float			y;
	int				z;
	int				color;
}					t_map;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_map			***map;
}					t_env;

/*
**fdf.c
*/
int					size_line(char **str);

/*
**display
*/
void				display(t_map ***map);

/*
**draw_line
*/
void				draw_line(t_map *point, t_map *point2, t_env *e);

void				convers(t_map ***map);
void				print(t_map ***map);

int					color(char *str);

/*
**parsing
*/
int					parse(char *str);
#endif
