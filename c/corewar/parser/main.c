/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:09:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 13:58:57 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char	*delete_tab_or_spaces(char *str)
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

void		print_list(t_list *list)
{
	while (list->start != 1)
		list = list->next;
	while (list->next->start != 1)
	{
		ft_putstr(list->str);
		ft_putnbr(list->type);
		write(1, "\n", 1);
		list = list->next;
	}
	ft_putstr(list->str);
	ft_putnbr(list->type);
	write(1, "\n", 1);
}

static int	facto_main(char **av, t_list **list)
{
	int		fd;
	char	*line;

	fd = 0;
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_error(1);
		return (FALSE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0' && line[0] != '#')
		{
			if (line[0] == ' ' || line[0] == '\t')
				ft_list_push(delete_tab_or_spaces(line), list);
			else
				ft_list_push(line, list);
		}
	}
	if (line[0])
		ft_strdel(&line);
	close(fd);
	return (TRUE);
}

int			main(int ac, char **av)
{
	t_list	*list;

	(void)g_op_tab;
	list = NULL;
	if (ac < 2)
		ft_error(FALSE);
	else
	{
		if (facto_main(av, &list) == FALSE)
			return (FALSE);
		if (ft_pars_lex(&list) == FALSE)
			return (FALSE);
		print_list(list);
	}
	return (TRUE);
}
