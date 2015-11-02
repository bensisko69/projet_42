/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 19:53:10 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 18:57:57 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"
#include "termcaps.h"

void		show_prompt(t_context *context)
{
	char	*ps1;
	char	*prompt;

	ps1 = environ_get(context, VAR_PS1);
	if (!ps1)
		ps1 = variables_get(context->vars, VAR_PS1);
	if (!ps1)
		ps1 = DEFAULT_PROMPT;
	prompt = format_prompt(context, ps1);
	ft_putstr_fd(prompt, tty_fd());
	free(prompt);
}
