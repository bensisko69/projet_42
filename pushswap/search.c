/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 13:58:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/05/18 17:26:23 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_int_min(t_list *l_a)
{
	int		min;
	int		turn;
	int		pos;

	turn = 0;
	pos = 0;
	min = l_a->dt;
	l_a = l_a->next;
	while (l_a->fst != TRUE)
	{
		turn++;
		if (l_a->dt < min)
		{
			pos = turn;
			min = l_a->dt;
		}
		l_a = l_a->next;
	}
	return (pos);
}

void		push_swap(t_list **l_a, t_list **l_b, int b)
{
	int		pos;

	if (size_list(*l_a) == 1)
		return ;
	while (size_list(*l_a) != 0)
	{
		pos = search_int_min(*l_a);
		while (pos--)
			ra(l_a, "ra ");
		push_a_in_b(l_a, l_b, "pa ");
		if (b == 1)
		{
			print_list(*l_a);
			print_list(*l_b);
		}
	}
	while (size_list(*l_b) != 0)
	{
		push_a_in_b(l_b, l_a, "pb ");
		if (b == 1)
		{
			print_list(*l_a);
			print_list(*l_b);
		}
	}
}
