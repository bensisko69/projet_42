/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 14:07:54 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/05 18:42:33 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "environ.h"
#include "parser.h"

int			b_unsetenv(t_context *context, t_list *args)
{
	size_t	arg_count;
	size_t	i;

	arg_count = ft_lstsize(args);
	if (arg_count == 1)
		return (builtin_error(UNSETENV_BUILTIN, ERR_TOO_FEW_ARGS, 0));
	i = 1;
	while (i < arg_count)
	{
		environ_remove(context, token_value(args, i + 1));
		++i;
	}
	return (BUILTIN_SUCCESS);
}
