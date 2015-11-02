/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_lexer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 18:01:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/11/25 17:33:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_error_lexer(int nb)
{
	int			i;
	static char	*tab[] = {MORE_CMT, MORE_NAME, OPP_OBL, MORE_NAME_LABEL, DEF};

	(void)g_op_tab;
	i = 0;
	while (i < 6)
	{
		if (i == nb)
			ft_putendl_fd((const char *)tab[i], 2);
		i++;
	}
}
