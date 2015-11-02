/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:07:49 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/05 18:39:14 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "parser.h"
#include "environ.h"

int			b_setenv(t_context *context, t_list *args)
{
	size_t	arg_count;
	char	*new_key;
	char	*new_value;

	arg_count = ft_lstsize(args);
	if (arg_count > 3)
		return (builtin_error(SETENV_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	if (arg_count == 1)
		environ_display(context->env_vars);
	else
	{
		new_key = token_value(args, 2);
		new_value = token_value(args, 3);
		environ_set(context, new_key, new_value);
	}
	return (BUILTIN_SUCCESS);
}
