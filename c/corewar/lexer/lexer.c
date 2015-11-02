/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 17:25:00 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:10:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int			check_label(t_list **list)
{
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	if ((*list)->type == 3)
	{
		if ((*list)->next->type == 4)
			return (TRUE);
		else
		{
			ft_error_lexer(2);
			return (FALSE);
		}
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 3)
		{
			if ((*list)->next->type == 4)
				return (TRUE);
			else
			{
				ft_error_lexer(2);
				return (FALSE);
			}
		}
		(*list) = (*list)->next;
	}
}

static int	facto_db_label(t_list **list)
{
	t_list	*temp;

	if ((*list)->type == 3)
	{
		temp = (*list)->next;
		while (temp->next != (*list))
		{
			if (temp->type == 3)
			{
				if (ft_strcmp(temp->str, (*list)->str) == 0)
				{
					ft_error_lexer(3);
					return (FALSE);
				}
			}
			temp = temp->next;
		}
	}
	return (TRUE);
}

int			check_db_lable(t_list **list)
{
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	if ((*list)->type == 3)
	{
		if (facto_db_label(list) == FALSE)
			return (FALSE);
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 3)
		{
			if (facto_db_label(list) == FALSE)
				return (FALSE);
		}
		(*list) = (*list)->next;
	}
	return (TRUE);
}

int			verif_arg(int nb_arg, char *str, int i)
{


	return (TRUE);
}

int			arg(char *str, t_list **list)
{
	t_func	func[] = {DEF_FUNC};
	size_t	i;

	i = 0;
	while (i < sizeof(func) / sizeof(t_func))
	{
		if (func[i].nb_line == ((*list)->opcode - 1))
			return (func[i].func((*list)->str, list));
		i++;
	}
	return (FALSE);
}

int			check_nb_arg(t_list **list)
{
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	if ((*list)->type == 4)
	{
		if (arg((*list)->str, list) == FALSE)
			return (FALSE);
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 4)
		{
			if (arg((*list)->str, list) == FALSE)
				return (FALSE);
		}
		(*list) = (*list)->next;
	}
	return (TRUE);
}

int			lexer(t_list **list)
{
	(void)g_op_tab;
	if (check_nb_cmt_or_name(list) == FALSE)
		return (FALSE);
	if (check_label(list) == FALSE)
		return (FALSE);
	if (check_inst(list) == FALSE)
		return (FALSE);
	if (check_db_lable(list) == FALSE)
		return (FALSE);
	if (check_nb_arg(list) == FALSE)
		return (FALSE);
	return (TRUE);
}
