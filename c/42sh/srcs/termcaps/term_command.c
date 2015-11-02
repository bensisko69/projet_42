/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 23:41:52 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:40:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

int			tputs_putchar(int c)
{
	return (write(tty_fd(), &c, 1));
}

void		term_command(char *capability)
{
	char	*command_string;

	command_string = tgetstr(capability, 0);
	if (command_string)
		tputs(command_string, 1, tputs_putchar);
	else
		shell_error(ERR_NO_SUCH_CAP, capability);
}

void		term_param_command(char *capability, int n)
{
	char	*command_string;

	command_string = tgetstr(capability, 0);
	if (command_string)
		tputs(tgoto(command_string, n, 0), 1, tputs_putchar);
	else
		shell_error(ERR_NO_SUCH_CAP, capability);
}

void		term_command_n(char *capability, size_t n)
{
	while (n--)
		term_command(capability);
}
