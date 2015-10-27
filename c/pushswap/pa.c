/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 15:21:00 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 19:07:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

void	push_link(t_list *link, t_list **liste, int fst)
{
	if (!(*liste))
	{
		(*liste) = link;
		link->fst = TRUE;
		(*liste)->next = (*liste);
		(*liste)->previous = (*liste);
	}
	else
	{
		link->previous = (*liste)->previous;
		link->next = (*liste);
		link->fst = fst;
		(*liste)->previous->next = link;
		(*liste)->previous = link;
		if (fst == TRUE)
		{
			(*liste)->fst = FALSE;
			(*liste)->previous->fst = TRUE;
			(*liste) = (*liste)->previous;
		}
	}
}

void	delete(t_list **link)
{
	if (size_list(*link) == 1)
		*link = NULL;
	if (!*link)
		return ;
	(*link)->next->previous = (*link)->previous;
	(*link)->previous->next = (*link)->next;
	if ((*link)->fst == TRUE)
		(*link)->next->fst = TRUE;
}

int		size_list(t_list *l_a)
{
	int		size;

	size = 0;
	if (!l_a)
		return (0);
	while (l_a->fst == FALSE || size == 0)
	{
		l_a = l_a->next;
		size++;
	}
	return (size);
}

void	push_a_in_b(t_list **l_a, t_list **l_b, char *func)
{
	t_list	*tmp;

	tmp = (*l_a);
	delete(l_a);
	if (*l_a)
		(*l_a) = tmp->next;
	push_link(tmp, l_b, TRUE);
	if (ft_strcmp(func, "pa ") == 0)
	{
		ft_putstr(RED);
		ft_putstr(func);
	}
	if (ft_strcmp(func, "pb ") == 0)
	{
		ft_putstr(BLUE);
		ft_putstr(func);
	}
	ft_putstr(DEFAULT);
}
