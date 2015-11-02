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
#include "parser.h"

int			b_exit(t_context *context, t_list *args)
{
	size_t	arg_count;
	int		exit_code;

	arg_count = ft_lstsize(args);
	if (arg_count > 2)
		return (builtin_error(EXIT_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	exit_code = EXIT_SUCCESS;
	if (arg_count == 2)
		exit_code = ft_atoi(token_value(args, 2));
	shell_exit(context, exit_code);
	return (BUILTIN_SUCCESS);
}
