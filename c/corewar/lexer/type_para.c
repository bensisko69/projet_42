/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_para.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 14:25:30 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 19:29:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int			parse_reg(t_list **list, char *str, int pos)
{
	int		i;
	char	*nbr;

	(void)g_op_tab;
	i = -1;
	nbr = (char *)malloc(sizeof(char) * 6);
	if (nbr == NULL)
		return (0);
	if (str[pos] == 'r')
	{
		while (str[pos++] != ' ' && str[pos])
			nbr[++i] = str[pos];
		i = ft_atoi(nbr);
		free(nbr);
		if (i > 16)
		{
			ft_error(3);
			return (0);
		}
		(*list)->type_arg = T_REG;
		return (TRUE);
	}
	else
		return (FALSE);
}

static int	dir_label(char *str, int *pos, t_list **list)
{
	int	size;
	while ((*list)->start != 1)
		(*list) = (*list)->next;
	if ((*list)->type == 3)
	{
		size = (ft_strlen((*list)->str) - 1);
		if (ft_strncmp((*list)->str, &str[*pos], size) == 0)
		{
			(*pos) += size;
			return (TRUE);
		}
	}
	(*list) = (*list)->next;
	while ((*list)->start != 1)
	{
		if ((*list)->type == 3)
		{
			size = (ft_strlen((*list)->str) - 1);
			if (ft_strncmp((*list)->str, &str[*pos], size) == 0)
			{
				(*pos) += size;
				return (TRUE);
			}
		}
		(*list) = (*list)->next;
	}
	return (TRUE);
}

static int	dir_nb(char *str, int *pos)
{
	while (str[(*pos)] != ' ' && str[(*pos)] != '\t' && str[(*pos)])
	{
		if (str[(*pos)] >= '0' && str[(*pos)] <= '9')
			(*pos)++;
		else
			return (FALSE);
	}
}

int			parse_dir(t_list **list, char *str, int *pos)
{
	(void)g_op_tab;
	while (str[(*pos)] && (str[(*pos)] == ' ' || str[(*pos)] == '\t'))
		(*pos)++;
	if (str[(*pos)] == '%')
	{
		(*pos)++;
		if (str[(*pos)] == ':')
		{
			(*pos)++;
			ft_putstr(&str[*pos]);
			if (dir_label(str, pos, list) == FALSE)
				return (FALSE);
		}
		else if (dir_nb(str, pos) == FALSE)
			return (FALSE);
		(*list)->type_arg = T_DIR;
		return (TRUE);
	}
	else
		return (FALSE);
}
