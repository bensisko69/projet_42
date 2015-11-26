/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:44:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/26 14:39:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print(t_map *map)
{
	t_list	*it;

	it = map->rooms;
	ft_putnbr(map->nb_ants);
	write(1, "\n", 1);
	while (it != NULL)
	{
		ft_putstr(((t_room*)(it->content))->name);
		write(1, " ", 1);
		if (((t_room*)(it->content))->type_room != 3 && ((t_room*)(it->content))->type_room != 4)
		{
			ft_putnbr(((t_room*)(it->content))->x);
			write(1, " ", 1);
			ft_putnbr(((t_room*)(it->content))->y);
		}
		write(1, "\n", 1);
		it = it->next;
	}
	it = map->noeuds;
	while (it != NULL)
	{
		ft_putstr(((t_noeud*)(it->content))->name_left);
		write(1, " ", 1);
		ft_putendl(((t_noeud*)(it->content))->name_right);
		it = it->next;
	}
}
