/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rainbow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 15:39:18 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/17 15:44:02 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	show_rainbow(void)
{
	size_t	i;

	i = 0;
	while (i < 256)
	{
		ft_setfgcolor((t_uchar)i);
		ft_putnbr(i++);
		WRITE(STDOUT, "\t");
		ft_resetcolor();
	}
	WRITE(STDOUT, "\n");
}

int			b_rainbow(t_context *context, t_list *args)
{
	size_t	arg_count;

	UNUSED(context);
	arg_count = ft_lstsize(args);
	if (arg_count > 1)
		return (builtin_error(RAINBOW_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	show_rainbow();
	return (BUILTIN_SUCCESS);
}
