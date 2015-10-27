/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/29 17:41:40 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/15 17:46:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		ft_erreur(char *cmd, char *error, char *info)
{
	ft_putstr_fd(cmd, 2);
	write(2, " : ", 3);
	ft_putstr_fd(error, 2);
	if (info)
	{
		write(2, " : ", 3);
		ft_putstr_fd(info, 2);
	}
	ft_putchar_fd('\n', 2);
}

char		*search(t_list *list, char *var_name)
{
	while (list && list != NULL)
	{
		if (ft_strncmp(list->str, var_name, ft_strlen(var_name)) == 0)
			return (list->str);
		list = list->next;
	}
	return (NULL);
}
