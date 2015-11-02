/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/28 22:10:17 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:30:42 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "prompt.h"
#include "termcaps.h"

/*
** - Restores the terminal state
** - Frees :
**   - The main context
**   - The builtin map
**   - The node map
**   - The job initialisation map
**   - The signal description map
**   - The prompt command map
**   - The key map
** - Closes the tty file descriptor
*/
void	shell_exit(t_context *context, int exit_code)
{
	term_restore_mode(context);
	set_fg_job(context, 0);
	free_context(context);
	free_builtins();
	free_node_map();
	free_job_init_map();
	free_signal_names_map();
	free_command_map();
	free_key_map();
	close_tty();
	_exit(exit_code);
}
