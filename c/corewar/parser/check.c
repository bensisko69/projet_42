/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 17:04:16 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:26:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	check_tab(char *str, t_list **list)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (str[a] && str[a] != ' ' && str[a] != '\t')
		a++;
	while (g_op_tab[i].nb_para != 0)
	{
		if ((ft_strncmp(g_op_tab[i].inst, str, a) == 0) && (*list)->type == 0)
		{
			(*list)->type = 4;
			(*list)->opcode = g_op_tab[i].opcode;
		}
		i++;
	}
}

int		check_start_end(char *str, t_list **list)
{
	if (ft_strncmp(".name ", str, 6) == 0)
	{
		if (cut_str(str, 7, list, 1) == -1)
		{
			ft_error(5);
			return (FALSE);
		}
		(*list)->type = 1;
		return (TRUE);
	}
	else if (ft_strncmp(".comment ", str, 9) == 0)
	{
		if (cut_str(str, 9, list, 2) == -2)
		{
			ft_error(6);
			return (FALSE);
		}
		(*list)->type = 2;
		return (TRUE);
	}
	else
		return (FALSE);
}

int		check_type(t_list **list)
{
	while ((*list)->start != 1)
		*list = (*list)->next;
	if ((*list)->type == 0)
		return (FALSE);
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 0)
			return (FALSE);
		(*list) = (*list)->next;
	}
	return (TRUE);
}
