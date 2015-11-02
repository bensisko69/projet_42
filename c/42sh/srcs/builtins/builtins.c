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

static void		free_builtin_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void			free_builtins(void)
{
	t_builtins	*builtins;

	builtins = get_builtins();
	ft_map_delete(*builtins, free_builtin_entry);
	free(builtins);
}

static void		add_builtin(t_builtins *builtins, char *name, t_builtin builtin)
{
	t_map_entry	entry;

	entry.key = name;
	entry.value = builtin;
	ft_map_insert(*builtins, entry, (t_simple_hash_func)ft_djb2);
}

t_builtins		*get_builtins(void)
{
	static t_builtins	*builtins = 0;

	if (!builtins)
	{
		builtins = (t_builtins *)ft_memalloc(sizeof(t_builtins));
		add_builtin(builtins, CD_BUILTIN, b_cd);
		add_builtin(builtins, ECHO_BUILTIN, b_echo);
		add_builtin(builtins, EXIT_BUILTIN, b_exit);
		add_builtin(builtins, ENV_BUILTIN, b_env);
		add_builtin(builtins, SETENV_BUILTIN, b_setenv);
		add_builtin(builtins, UNSETENV_BUILTIN, b_unsetenv);
		add_builtin(builtins, VARS_BUILTIN, b_vars);
		add_builtin(builtins, SET_BUILTIN, b_set);
		add_builtin(builtins, UNSET_BUILTIN, b_unset);
		add_builtin(builtins, EXPORT_BUILTIN, b_export);
		add_builtin(builtins, PID_BUILTIN, b_pid);
		add_builtin(builtins, SOURCE_BUILTIN, b_source);
		add_builtin(builtins, FG_BUILTIN, b_fg);
		add_builtin(builtins, RAINBOW_BUILTIN, b_rainbow);
		add_builtin(builtins, HISTORY_BUILTIN, b_history);
	}
	return (builtins);
}

t_builtin		get_builtin(const char *command_name)
{
	t_builtin	builtin;

	builtin = (t_builtin)ft_map_get(*get_builtins(),
									(char *)command_name,
									(t_simple_hash_func)ft_djb2);
	return (builtin);
}
