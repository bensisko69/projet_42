/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:35:36 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/16 22:39:20 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"
#include "environ.h"
#include "tools.h"

static void		dup_process_fds(t_process *process)
{
	if (process->fd_in != STDIN)
	{
		dup2(process->fd_in, STDIN);
		close(process->fd_in);
	}
	if (process->fd_out != STDOUT)
	{
		dup2(process->fd_out, STDOUT);
		close(process->fd_out);
	}
}

static int		check_command(char *command)
{
	if (access(command, F_OK) == -1)
	{
		shell_error(ERR_NO_SUCH_FILE, command);
		return (0);
	}
	else if (access(command, X_OK) == -1 || is_dir(command))
	{
		shell_error(ERR_DENIED, command);
		return (0);
	}
	return (1);
}

static void		exec_command(t_context *context, t_process *process,
							char *command)
{
	char		**env_array;
	char		**args;

	if (!check_command(command))
		_exit(EXEC_STATUS_NOK);
	args = tokens_as_char_array(process->args);
	args[0] = command;
	env_array = environ_array(context->env_vars);
	execve(command, args, env_array);
	shell_error(ERR_EXECVE, command);
	char_array_free(env_array);
	char_array_free(args);
	_exit(EXEC_STATUS_NOK);
}

void			start_process(t_context *context, t_process *process)
{
	char		*command_name;
	char		*command;
	t_builtin	builtin;

	reset_signals();
	dup_process_fds(process);
	command_name = token_value(process->args, 1);
	builtin = get_builtin(command_name);
	if (builtin)
		_exit(builtin(context, process->args));
	command = get_command_path(context, command_name);
	if (command)
		exec_command(context, process, command);
	shell_error(ERR_COMMAND_NOT_FOUND, command_name);
	_exit(EXEC_STATUS_NOK);
}
