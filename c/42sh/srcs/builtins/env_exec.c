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

#include "parser.h"
#include "environ.h"
#include "interpreter.h"
#include "tools.h"
#include "termcaps.h"

static int	exec(char **args, char **env, const char *base_name)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid != -1)
	{
		if (pid == 0)
		{
			if (!*args)
				shell_error(ERR_COMMAND_NOT_FOUND, base_name);
			execve(*args, args, env);
			exit(EXIT_ERROR);
		}
		else
		{
			waitpid(pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				return (BUILTIN_SUCCESS);
		}
	}
	else
		shell_error(ERR_FORK, 0);
	return (BUILTIN_ERROR);
}

static void	copy_one_entry(void *p_entry, void *data)
{
	t_map_entry	*entry;
	t_map		*map;
	t_map_entry	new_entry;

	entry = (t_map_entry *)p_entry;
	map = (t_map *)data;
	new_entry.key = ft_strdup(entry->key);
	new_entry.value = ft_strdup(entry->value);
	ft_map_insert(*map, new_entry, (t_simple_hash_func)ft_djb2);
}

static char	**env_dup(t_context *context, t_list *add, int rm_inherited)
{
	t_map		env_map;
	char		**env_array;
	t_map_entry	entry;
	char		*sep;

	ft_bzero(&env_map, sizeof(t_map));
	if (!rm_inherited)
		ft_map_foreach(*context->env_vars, copy_one_entry, &env_map);
	while (add)
	{
		sep = ft_strchr(add->content, ENVIRON_VAR_SEPARATOR);
		entry.key = ft_strsub(add->content, 0, sep - (char *)add->content);
		entry.value = ft_strdup(sep + 1);
		ft_map_insert(env_map, entry, (t_simple_hash_func)ft_djb2);
		add = add->next;
	}
	env_array = environ_array(&env_map);
	environ_delete(&env_map);
	return (env_array);
}

static char	**make_args(t_context *context, t_list *args)
{
	char	**array;
	char	*cmd;
	char	*arg;
	size_t	i;

	array = (char **)malloc(sizeof(char *) * (ft_lstsize(args) + 1));
	i = 0;
	while (args)
	{
		arg = get_token(&args)->lexeme;
		cmd = (i == 0 ? get_command_path(context, arg) : arg);
		array[i++] = cmd;
		args = args->next;
	}
	array[i] = 0;
	return (array);
}

int			env_exec(t_context *context, t_list *args,
						int remove_inherited, t_list *additional)
{
	t_list	*it;
	char	**env;
	char	**arg_array;
	int		ret;

	if (args)
	{
		env = env_dup(context, additional, remove_inherited);
		arg_array = make_args(context, args);
		ret = exec(arg_array, env, get_token(&args)->lexeme);
		ft_lstdel(&additional, (t_deleter)free);
		char_array_free(env);
		free(arg_array);
		return (ret);
	}
	if (!remove_inherited)
		environ_display(context->env_vars);
	it = additional;
	while (it)
	{
		ft_putendl_fd((char *)it->content, tty_fd());
		it = it->next;
	}
	ft_lstdel(&additional, (t_deleter)free);
	return (BUILTIN_SUCCESS);
}
