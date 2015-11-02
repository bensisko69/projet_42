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

int			b_echo(t_context *context, t_list *args)
{
	size_t	flag;

	UNUSED(context);
	flag = 0;
	args = args->next;
	if (args)
	{
		if (ft_strcmp(get_token(&args)->lexeme, "-n") == 0)
		{
			args = args->next;
			flag = 1;
		}
	}
	while (args)
	{
		ft_putstr(get_token(&args)->lexeme);
		if (args->next)
			ft_putchar(' ');
		args = args->next;
	}
	if (!flag)
		ft_putchar('\n');
	return (BUILTIN_SUCCESS);
}
