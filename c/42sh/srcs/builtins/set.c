/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 17:31:08 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 19:09:53 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtins.h"

static int	is_alnum_str(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (0);
		++str;
	}
	return (1);
}

int			b_set(t_context *context, t_list *args)
{
	size_t	arg_count;
	char	*new_key;
	char	*new_value;

	arg_count = ft_lstsize(args);
	if (arg_count > 3)
		return (builtin_error(SET_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	if (arg_count == 1)
		return (builtin_error(SET_BUILTIN, ERR_TOO_FEW_ARGS, 0));
	new_key = token_value(args, 2);
	if (!is_alnum_str(new_key))
		return (builtin_error(SET_BUILTIN, ERR_INVALID_NAME, new_key));
	new_value = token_value(args, 3);
	variables_set(context->vars, new_key, new_value);
	return (BUILTIN_SUCCESS);
}
