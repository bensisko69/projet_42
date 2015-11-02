/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trie.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/01 17:28:15 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/01 17:33:59 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

char	**ft_sort(char **f_tab)
{
	char	*tmp;
	int		a;
	int		i;
	int		j;

	j = 2;
	a = -1;
	while (f_tab[++a])
	{
		i = a + 1;
		while (f_tab[i])
		{
			while (f_tab[a][j] == f_tab[i][j])
				j++;
			if (f_tab[a][j] > f_tab[i][j])
			{
				tmp = f_tab[a];
				f_tab[a] = f_tab[i];
				f_tab[i] = tmp;
			}
			j = 2;
			i++;
		}
	}
	return (f_tab);
}
