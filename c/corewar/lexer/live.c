/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 10:04:02 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/26 16:19:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/parser.h"

int	live(char *str, t_list **list)
{
	int	i;

	i = 5;
	if (parse_dir(list, str, &i) == TRUE)
	{
		while (str[i] && str[i] != ';')
		{
			if (str[i] != ' ' && str[i] != '\t')
				return (FALSE);
			i++;
		}
		(*list)->type_arg = T_DIR;
		return (TRUE);
	}
	else
	{
		ft_error_lexer(4);
		return (FALSE);
	}
}