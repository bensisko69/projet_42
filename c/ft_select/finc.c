/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:08:23 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/02/25 11:52:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

extern t_termios	g_term_origin;

void	arrow_left(t_list **list, t_list **current)
{
	(void)list;
	*current = (*current)->previous;
}

void	arrow_right(t_list **list, t_list **current)
{
	(void)list;
	*current = (*current)->next;
}

void	esc(t_list **list, t_list **current)
{
	(void)current;
	(void)list;
	if (tcsetattr(0, TCSANOW, &g_term_origin) == 0)
		exit(0);
}

void	enter(t_list **list, t_list **current)
{
	int		flag;
	int		space;

	space = 0;
	*current = *list;
	flag = 0;
	term_command(CAP_CLEAR_SCREEN);
	while ((*current != *list || flag == 0) && (*current))
	{
		if ((*current)->select == 1)
		{
			if (space > 0)
				ft_putchar(' ');
			space++;
			ft_putstr((*current)->str);
		}
		*current = (*current)->next;
		flag++;
	}
	esc(list, current);
}

void	ft_delete(t_list **list, t_list **current)
{
	t_list	*tmp;

	tmp = *current;
	*current = (*current)->next;
	list_remove(list, tmp);
}
