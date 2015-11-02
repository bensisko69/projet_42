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
#include "environ.h"

static int	parse_opts(char *opts, int *flag)
{
	char	opt_err[2];

	*flag = 1;
	while (*opts)
	{
		if (*opts != 'i')
		{
			opt_err[0] = *opts;
			opt_err[1] = '\0';
			builtin_error(ENV_BUILTIN, ERR_ILLEGAL_OPTION, opt_err);
			return (0);
		}
		++opts;
	}
	return (1);
}

static int	env_args(t_context *context, t_list *args)
{
	char	*arg;
	int		remove_inherited;
	t_list	*additional;

	additional = 0;
	remove_inherited = 0;
	while (args)
	{
		arg = get_token(&args)->lexeme;
		if (*arg == '-' && !parse_opts(arg + 1, &remove_inherited))
			return (BUILTIN_ERROR);
		else if (*arg != '-')
			break ;
		args = args->next;
	}
	while (args)
	{
		arg = get_token(&args)->lexeme;
		if (!ft_strchr(arg, '='))
			break ;
		ft_lstappend(&additional, ft_lstnew(arg, ft_strlen(arg) + 1));
		args = args->next;
	}
	return (env_exec(context, args, remove_inherited, additional));
}

int			b_env(t_context *context, t_list *args)
{
	size_t	arg_count;

	arg_count = ft_lstsize(args);
	if (arg_count == 1)
		environ_display(context->env_vars);
	else
		return (env_args(context, args->next));
	return (BUILTIN_SUCCESS);
}
