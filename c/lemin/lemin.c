/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/26 14:44:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static char		*delete_tab_or_spaces(char *str)
{
	int		i;
	int		a;
	char	*str2;

	a = 0;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	str2 = (char *)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	while (str[i])
	{
		str2[a] = str[i];
		i++;
		a++;
	}
	str2[a] = '\0';
	return (str2);
}

int				main(int ac, char **av)
{
	t_list	*list;
	t_map	map;
	char	*line;
	int		fd;
	char	*str;

	list = NULL;
	ft_bzero(&map, sizeof(map));
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (FALSE);
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] == ' ' || line[0] == '\t')
			{
				str = delete_tab_or_spaces(line);
				if (str && str[0] == '#' && str[1] != '#')
					continue;
				ft_lstappend(&list, ft_lstnew(str, ft_strlen(str)));
			}
			if (line[0] != '\0')
			{
				if (str && str[0] == '#' && str[1] != '#' )
					continue;
				ft_lstappend(&list, ft_lstnew(line, ft_strlen(line)));
			}
		}
		if (line && line[0] == '\0')
			free(line);
		if (list)
		{
			if (parse(&list, &map) == TRUE)
			{
				ft_putendl("GOOD JOB GUY!!!");
				lexer(&map);
			}
			print(&map);
		}
	}
	return (FALSE);
}
