/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:52:52 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:14:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>

#include "environ.h"
#include "tools.h"

static void		free_command(void *key, void *value)
{
	free(key);
	free(value);
}

void			commands_delete(t_commands *commands)
{
	ft_map_delete(*commands, free_command);
}

static void		add_entry_if(t_commands *commands, char *file_name, char *path)
{
	t_map_entry	entry;

	if (is_file(path))
	{
		entry.key = file_name;
		entry.value = path;
		ft_map_insert(*commands, entry, (t_simple_hash_func)ft_djb2);
	}
	else
	{
		free(file_name);
		free(path);
	}
}

static void		list_commands_in_dir(t_commands *commands, const char *dir_name)
{
	DIR			*dir;
	t_dirent	*dir_entry;
	char		*file_name;
	char		*full_path;

	dir = opendir(dir_name);
	if (dir)
	{
		while ((dir_entry = readdir(dir)))
		{
			file_name = ft_strsub(dir_entry->d_name, 0, dir_entry->d_namlen);
			full_path = path_join(dir_name, file_name);
			add_entry_if(commands, file_name, full_path);
		}
		closedir(dir);
	}
}

void			list_commands(t_context *context)
{
	char		*path;
	char		**dirs;
	size_t		i;

	commands_delete(context->commands);
	path = environ_get(context, VAR_PATH);
	if (path)
	{
		dirs = ft_strsplit(path, PATH_DIR_SEPARATOR);
		i = 0;
		while (dirs[i])
		{
			list_commands_in_dir(context->commands, dirs[i]);
			++i;
		}
		char_array_free(dirs);
	}
}
