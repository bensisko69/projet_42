/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:01:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:26:10 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_error(int nb)
{
	int			i;
	static char	*tab[] = {ERO_ARG, ERO_OPEN, ERO_NM_OR_CMT, ERO_NBR, DEF_ER_LX};

	(void)g_op_tab;
	i = 0;
	while (i < 7)
	{
		if (i == nb)
			ft_putendl_fd((const char *)tab[i], 2);
		i++;
	}
}
