/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:54:43 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/12 16:00:25 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	shell_error(const char *what, const char *info)
{
	WRITE(STDERR, SHELL_ERROR_PREFIX);
	WRITE(STDERR, ": ");
	ft_putstr_fd(what, STDERR);
	if (info)
	{
		WRITE(STDERR, ": ");
		ft_putstr_fd(info, STDERR);
	}
	WRITE(STDERR, "\n");
}
