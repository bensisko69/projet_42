/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:11:24 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/11 13:40:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static t_list	*create_ellem(int type, void *data)
{
	t_list	*new_link;

	new_link = (t_list *)malloc(sizeof(* new_link));
	if (new_link)
	{
        new_link->type = type;
        new_link->data = data;
		new_link->next = new_link;
		new_link->prev = new_link;
	}
	return (new_link);
}

void    ft_iter_label(t_list *list, void (*f)(void *, t_list *))
{
    t_list *e;
    
    if (!list)
        return ;
    e = list;
    if (list->start == 1)
        list = list->next;
    while(list->start != 1)
    {
        if (list->type == ITERLABEL)
            f(list->data, e);
        list = list->next;
    }
    if (list->type == ITERLABEL)
        f(list->data, e);
}

void	ft_list_push(int type, void *data, t_list **list)
{
	(void)g_op_tab;
	t_list	*new_link;

	new_link = create_ellem(type, data);
	if ((*list) == NULL)
	{
		new_link->start = 1;
		*list = new_link;
	}
	else
	{
		while((*list)->start != 1)
			*list = (*list)->next;
		new_link->start = 0;
		new_link->next = (*list)->next;
		new_link->prev = *list;
		(*list)->next = new_link;
		new_link->next->prev = new_link;
	}
}