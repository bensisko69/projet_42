/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:32:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/27 13:16:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	builtin_error(const char *name, const char *error, const char *info)
{
	ft_putstr_fd(name, STDERR);
	WRITE(STDERR, ERR_SEPARATOR);
	ft_putstr_fd(error, STDERR);
	if (info)
	{
		WRITE(STDERR, ERR_SEPARATOR);
		ft_putstr_fd(info, STDERR);
	}
	ft_putchar_fd('\n', STDERR);
	return (BUILTIN_ERROR);
}
