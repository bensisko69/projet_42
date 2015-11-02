/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 15:50:37 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 15:53:49 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int			b_pid(t_context *context, t_list *args)
{
	size_t	arg_count;

	UNUSED(context);
	arg_count = ft_lstsize(args);
	if (arg_count > 1)
		return (builtin_error(PID_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	ft_putnbr(getpid());
	ft_putchar('\n');
	return (BUILTIN_SUCCESS);
}
