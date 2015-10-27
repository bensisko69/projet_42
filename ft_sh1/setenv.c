/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/28 16:31:11 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/15 16:12:02 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_setenv(t_list **list, char *line)
{
	char	**cmp;
	char	*cmp2;
	char	*cmp3;

	cmp = ft_strsplit(line, ' ');
	if (char_array_size(cmp) >= 3)
	{
		if (search(*list, cmp[1]) == 0)
		{
			cmp2 = join(cmp[1], "=", cmp[2]);
			ft_link(list, cmp2);
		}
		else
		{
			cmp3 = search(*list, cmp[1]);
			cmp2 = join(cmp[1], "=", cmp[2]);
			exchange_content(*list, cmp3, cmp2);
		}
	}
	else
		ft_putstr("setenv: not enough argument\n");
	free_char_array(cmp);
}

int		ft_strlen_char(char *str, char symb)
{
	int	i;

	i = 0;
	while (str[i] != symb)
		i++;
	return (i);
}

void	exchange_content(t_list *list, char *cmp2, char *cmp3)
{
	while (list != NULL)
	{
		if (ft_strnequ(list->str, cmp2, ft_strlen_char(list->str, '=')))
		{
			free(list->str);
			list->str = cmp3;
			break ;
		}
		list = list->next;
	}
}

void	show_prompt(t_list *list)
{
	char	*pwd;
	char	**path_components;
	char	*prompt;
	int		component_count;

	pwd = search(list, "PWD=") + 4;
	path_components = ft_strsplit(pwd, '/');
	write(1, "[POKEMON] ", 10);
	component_count = char_array_size(path_components);
	if (component_count < 2)
		ft_putstr(pwd);
	else
	{
		prompt = join(path_components[component_count - 2], "/",
						path_components[component_count - 1]);
		ft_putstr(prompt);
		free(prompt);
	}
	write(1, " > ", 3);
	free_char_array(path_components);
}
