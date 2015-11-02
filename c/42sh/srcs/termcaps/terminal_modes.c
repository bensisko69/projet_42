/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_modes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 21:45:09 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:54:10 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "environ.h"

void			termcaps_init(t_context *context)
{
	char		*term_type;

	term_type = environ_get(context, VAR_TERM);
	if (!term_type)
	{
		shell_error(ERR_NO_TERM_TYPE, 0);
		_exit(EXIT_ERROR);
	}
	if (tgetent(0, term_type) != 1)
	{
		shell_error(ERR_ENTRY_LOAD, term_type);
		_exit(EXIT_ERROR);
	}
}

void			term_set_raw_mode(t_context *context)
{
	t_termios	term;

	if (tcgetattr(tty_fd(), &term) == -1)
	{
		shell_error(ERR_TCGETATTR, 0);
		shell_exit(context, EXIT_ERROR);
	}
	ft_memcpy(&context->term_state, &term, sizeof(t_termios));
	term.c_lflag &= ~(ICANON | ECHO | ISIG);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(tty_fd(), TCSAFLUSH, &term) == -1)
	{
		shell_error(ERR_TCSETATTR, 0);
		shell_exit(context, EXIT_ERROR);
	}
}

void			term_restore_mode(t_context *context)
{
	if (tcsetattr(tty_fd(), TCSAFLUSH, &context->term_state) == -1)
		shell_error(ERR_TCSETATTR, 0);
}
