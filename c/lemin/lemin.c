/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/27 18:22:23 by lrenoud-         ###   ########.fr       */
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
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	str2 = (char*)malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	while (str[i])
	{
		str2[a] = str[i];
		i++;
		a++;
	}
	str2[a] = '\0';
	return (str2);
}

void			free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void			free_list(t_list *list)
{
	t_list	*it;

	while (list)
	{
		it = list;
		free(it->content);
		list = list->next;
		free(it);
	}
}

void			free_room(t_list *room)
{
	t_list	*it;

	it = room;
	while (room)
	{
		it = room;
		free(((t_room*)(it->content))->name);
		room = room->next;
		free(it->content);
		free(it);
	}
}

void			free_noeud(t_list *noeud)
{
	t_list	*it;

	it = noeud;
	while (noeud)
	{
		it = noeud;
		free(((t_noeud*)(it->content))->name_left);
		free(((t_noeud*)(it->content))->name_right);
		noeud = noeud->next;
		free(it->content);
		free(it);
	}
}

void			free_map(t_map *map)
{
	free_room(map->rooms);
	free_noeud(map->noeuds);
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
				ft_lstappend(&list, ft_lstnew(str, ft_strlen(str) + 1));
				free(str);
			}
			if (line[0] != '\0')
			{
				if (line && line[0] == '#' && line[1] != '#' )
					continue;
				ft_lstappend(&list, ft_lstnew(line, ft_strlen(line) + 1));
			}
			free(line);
		}
		if (list)
		{
			if (parse(list, &map) == TRUE)
			{
				if (lexer(&map) == TRUE)
					ft_putendl("GOOD JOB GUY!!!");
				else
					ft_putendl("DE LA MERDE LEXER");
			}
			else
				ft_putendl("DE LA MERDE PARSE");
			print(&map);
		}

		free_list(list);
		free_map(&map);
	}
	return (FALSE);
}
