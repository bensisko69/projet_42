/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/25 12:28:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/29 15:58:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_line(int a, char **str, t_map ***map)
{
	int	c;

	c = 0;
	while (str[c])
	{
		map[a][c] = malloc(sizeof(t_map));
		if (map[a][c] == NULL)
			return ;
		map[a][c]->y = (float)a * SIZE_PIXEL;
		map[a][c]->x = (float)c * SIZE_PIXEL;
		map[a][c]->color = color(str[c]);
		map[a][c]->z = ft_atoi(str[c]);
		c++;
	}
}

static void		ft_read(int fd, t_map ***map)
{
	char	*line;
	char	**str;
	int		a;
	int		size;

	a = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (parse(line) == 1)
			exit(1);
		str = ft_strsplit(line, ' ');
		size = size_line(str);
		ft_putnbr(size);
		map[a] = (t_map **)malloc((sizeof(t_map *) * (size + 1)));
		if (map[a] == NULL)
			return ;
		map[a][size] = NULL;
		ft_line(a, str, map);
		a++;
		free(line);
		free(str);
	}
	convers(map);
	display(map);
}

static int		ft_nbr_line(char *str)
{
	int		fd;
	int		size;
	char	buff[1];
	char	tmp;

	tmp = 0;
	size = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, buff, 1) == 1)
	{
		if (buff[0] == '\n')
			size++;
		tmp = buff[0];
	}
	close(fd);
	if (tmp != '\n')
		return (size + 1);
	return (size);
}

int				main(int ac, char **av)
{
	int		fd;
	t_map	***map;
	int		size;

	if (ac == 2)
	{
		size = ft_nbr_line(av[1]);
		map = malloc((size + 1) * sizeof(t_map **));
		if (map == NULL)
			return (-1);
		ft_bzero(map, (size + 1) * sizeof(t_map **));
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			return (1);
		ft_read(fd, map);
		close(fd);
		return (0);
	}
	ft_putstr_fd("usage : ./fdf file1\n", 2);
	return (1);
}
