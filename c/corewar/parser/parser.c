/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:52:29 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:23:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		cut_str(char *str, int cut, t_list **list, int c)
{
	int		i;
	int		size;

	size = ft_strlen(str) - 1;
	if (c == 2 && size > 2048)
		return (-2);
	else if (c == 1 && size > 128)
		return (-1);
	i = 0;
	while (cut < size)
	{
		if (c == 1)
			(*list)->header.prog_name[i] = str[cut];
		else
			(*list)->header.comment[i] = str[cut];
		i++;
		cut++;
	}
	if (c == 1)
		(*list)->header.prog_name[i] = '\0';
	else
		(*list)->header.comment[i] = '\0';
	(*list)->header.magic = COREWAR_EXEC_MAGIC;
	return (TRUE);
}

void		parse_op(t_list **list)
{
	int	i;

	i = 0;
	while ((*list)->start != 1)
		*list = (*list)->next;
	if (((*list)->type != 1) || ((*list)->type != 2) || ((*list)->type != 3))
		check_tab((*list)->str, list);
	*list = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type != 1 || (*list)->type != 2 || (*list)->type != 3)
			check_tab((*list)->str, list);
		*list = (*list)->next;
	}
}

void		parse_label(t_list **list)
{
	int	i;

	i = 0;
	while ((*list)->start != 1)
		*list = (*list)->next;
	if (((*list)->type != 1) && ((*list)->type != 2))
	{
		if ((*list)->str[ft_strlen((*list)->str) - 1] == ':')
		{
			while (ft_isalnum((*list)->str[i]) == 1)
				i++;
			if (ft_strlen((*list)->str) == (i + 1))
				(*list)->type = 3;
			else
				ft_error_lexer(5);
		}
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if (((*list)->type != 1) || ((*list)->type != 2))
		{
			if ((*list)->str[ft_strlen((*list)->str) - 1] == ':')
			{
				i = 0;
				while (ft_isalnum((*list)->str[i]) == 1)
					i++;
				if (ft_strlen((*list)->str) == (i + 1))
					(*list)->type = 3;
				else
					ft_error_lexer(5);
			}
		}
		(*list) = (*list)->next;
	}
}

int			parse(t_list **list)
{
	int	i;

	i = 42;
	while ((*list)->start != 1)
		*list = (*list)->next;
	*list = (*list)->next;
	while ((*list)->start != 1)
	{
		i += check_start_end((*list)->str, list);
		*list = (*list)->next;
	}
	i += check_start_end((*list)->str, list);
	if (i < 2)
	{
		ft_error(2);
		return (FALSE);
	}
	parse_label(list);
	parse_op(list);
	if (check_type(list) == FALSE)
		return (FALSE);
	return (TRUE);
}

int			ft_pars_lex(t_list **list)
{
		int ret;

	ret = 0;
	if (!(*list))
		return (FALSE);
	if (ret = parse(list) == TRUE)
	{

		if (ret = lexer(list) == TRUE)
		{
			return (TRUE);
		}
		else
			return (FALSE);
	}
	else
		return (FALSE);
}
