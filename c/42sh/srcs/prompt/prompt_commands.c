/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 22:07:08 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/19 16:21:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static void				add_to_map(t_map *map, char *key, t_prompt_command comm)
{
	t_map_entry			entry;

	entry.key = key;
	entry.value = comm;
	ft_map_insert(*map, entry, (t_simple_hash_func)ft_djb2);
}

static t_map			*get_command_map(void)
{
	static t_map		*map = 0;

	if (!map)
	{
		map = (t_map *)ft_memalloc(sizeof(t_map));
		add_to_map(map, USER_NAME_COMMAND, user_name_command);
		add_to_map(map, PATH_COMMAND, path_command);
		add_to_map(map, START_BOLD_COMMAND, start_bold_command);
		add_to_map(map, END_BOLD_COMMAND, end_bold_command);
		add_to_map(map, SH_LVL_COMMAND, sh_lvl_command);
		add_to_map(map, JOBS_NUMBER_COMMAND, jobs_number_command);
		add_to_map(map, END_UNDERLINE_COMMAND, end_underline_command);
		add_to_map(map, START_UNDERLINE_COMMAND, start_underline_command);
		add_to_map(map, START_ITALIC_COMMAND, start_italic_command);
		add_to_map(map, END_ITALIC_COMMAND, end_italic_command);
		add_to_map(map, LAST_STATUS_COMMAND, last_status_command);
		add_to_map(map, TIME_24_COMMAND, time_24_command);
		add_to_map(map, TIME_12_COMMAND, time_12_command);
		add_to_map(map, START_REVERSE_COMMAND, start_reverse_command);
		add_to_map(map, END_REVERSE_COMMAND, end_reverse_command);
		add_to_map(map, NAME_MACHINE, name_machine_command);
		add_to_map(map, NAME_MACHINE_TRUNCATED, name_machine_truncated_command);
	}
	return (map);
}

static void				free_command_map_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void					free_command_map(void)
{
	t_map				*command_map;

	command_map = get_command_map();
	ft_map_delete(*command_map, free_command_map_entry);
	free(command_map);
}

void					fetch_command(t_context *context, t_token *token)
{
	t_prompt_command	command;
	size_t				n;
	size_t				i;

	n = 0;
	i = 0;
	while (ft_isdigit(token->lexeme[i]))
		n = n * 10 + token->lexeme[i++] - '0';
	command = (t_prompt_command)ft_map_get(*get_command_map(),
											token->lexeme + i,
											(t_simple_hash_func)ft_djb2);
	if (command)
	{
		free(token->lexeme);
		token->lexeme = command(context, n);
	}
	token->type = CHARS;
}
