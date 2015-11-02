/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 18:25:25 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/14 20:06:29 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "environ.h"
#include "builtins.h"

int			b_export(t_context *context, t_list *args)
{
	size_t	arg_count;
	size_t	i;
	char	*key;
	char	*value;

	arg_count = ft_lstsize(args);
	if (arg_count == 1)
		return (builtin_error(EXPORT_BUILTIN, ERR_TOO_FEW_ARGS, 0));
	i = 1;
	while (i < arg_count)
	{
		key = token_value(args, i + 1);
		value = variables_get(context->vars, key);
		if (value)
			environ_set(context, key, value);
		++i;
	}
	return (BUILTIN_SUCCESS);
}
