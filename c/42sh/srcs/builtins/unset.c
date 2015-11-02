/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:42:08 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/05 17:51:55 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtins.h"

int		b_unset(t_context *context, t_list *args)
{
	size_t	arg_count;
	size_t	i;

	arg_count = ft_lstsize(args);
	if (arg_count == 1)
		return (builtin_error(UNSET_BUILTIN, ERR_TOO_FEW_ARGS, 0));
	i = 1;
	while (i < arg_count)
	{
		variables_remove(context->vars, token_value(args, i + 1));
		++i;
	}
	return (BUILTIN_SUCCESS);
}
