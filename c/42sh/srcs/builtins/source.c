/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 20:28:11 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 20:34:37 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "interpreter.h"

int			b_source(t_context *context, t_list *args)
{
	size_t	arg_count;

	arg_count = ft_lstsize(args);
	if (arg_count < 2)
		return (builtin_error(SOURCE_BUILTIN, ERR_TOO_FEW_ARGS, 0));
	if (arg_count > 2)
		return (builtin_error(SOURCE_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	return (exec_file(context, token_value(args, 2)));
}
