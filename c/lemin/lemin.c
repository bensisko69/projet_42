/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/29 15:16:00 by lrenoud-         ###   ########.fr       */
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
	t_liste	*list;
	char	*line;
	int		fd;

	list = NULL;
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_error(1, "");
			return (FALSE);
		}
		while (get_next_line(fd, &line) > 0)
		{
			if (line[0] == ' ' || line[0] == '\t')
				ft_liste_push(delete_tab_or_spaces(line), &list);
			if (line[0] != '\0')
				ft_liste_push(line, &list);
		}
		if (line[0] == '\0')
			free(line);
		if (parse(&list) == FALSE)
		{
			ft_error(2, list->previous->str);
			return (FALSE);
		}
		if (lexer(&list) == FALSE)
			return (FALSE);
		// print_liste(list);
	}
}
