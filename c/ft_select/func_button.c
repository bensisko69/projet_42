/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/12 15:37:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/02/13 14:58:49 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"
#include "func_button.h"

void	space(t_list **list, t_list **current)
{
	(void)list;
	(*current)->select = !(*current)->select;
	*current = (*current)->next;
}

void	key_pressed(t_list **list, t_list **current, char *key_code)
{
	static t_key	key[] = {TAB};
	size_t			i;

	i = 0;
	while (i < sizeof(key) / sizeof(t_key))
	{
		if (ft_strcmp(key[i].key_code, key_code) == 0)
		{
			key[i].func(list, current);
			break ;
		}
		i++;
	}
}
