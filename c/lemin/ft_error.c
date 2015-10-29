/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 15:28:19 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/29 14:14:46 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	puts(char *error, char *line)
{
	ft_putstr_fd(error, 2);
	ft_putstr_fd(" at line ", 2);
	ft_putendl_fd(line, 2);
}

void	ft_error(int nbr, char *str)
{
	if (nbr == 1)
		ft_putendl_fd(OPEN_FALED, 2);
		// puts(OPEN_FALED, str);
	else if (nbr == 2)
		puts(PARSE_ERROR, str);
}
