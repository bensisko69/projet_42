/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 15:21:00 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 19:26:23 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_list **l_a, char *func)
{
	(*l_a)->next->fst = TRUE;
	(*l_a)->fst = FALSE;
	(*l_a) = (*l_a)->next;
	if (ft_strcmp(func, "ra ") == 0)
	{
		ft_putstr(PURPLE);
		ft_putstr(func);
	}
	if (ft_strcmp(func, "rb ") == 0)
	{
		ft_putstr(CYAN);
		ft_putstr(func);
	}
	ft_putstr(DEFAULT);
}
