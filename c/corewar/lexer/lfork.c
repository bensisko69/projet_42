/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:11:48 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:12:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	lfork(char *str, t_list **list)
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
		return (FALSE);
}