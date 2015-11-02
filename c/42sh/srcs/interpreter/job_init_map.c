/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_init_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 18:09:48 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:22:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interpreter.h"

static void		free_job_init_map_entry(void *key, void *value)
{
	UNUSED(key);
	UNUSED(value);
}

void			free_job_init_map(void)
{
	t_map		*job_init_map;

	job_init_map = get_job_init_map();
	ft_map_delete(*job_init_map, free_job_init_map_entry);
	free(job_init_map);
}

static void		add_to_map(t_map *map, t_token_type type, t_job_builder builder)
{
	t_map_entry	entry;

	entry.key = &type;
	entry.value = builder;
	ft_map_insert(*map, entry, token_type_hash);
}

t_map			*get_job_init_map(void)
{
	static t_map	*job_init_map = 0;

	if (!job_init_map)
	{
		job_init_map = (t_map *)ft_memalloc(sizeof(t_map));
		add_to_map(job_init_map, OP_LREDIR, job_set_stdin);
		add_to_map(job_init_map, OP_RREDIR, job_set_stdout_trunc);
		add_to_map(job_init_map, OP_DRREDIR, job_set_stdout_append);
		add_to_map(job_init_map, OP_PIPE, job_add_pipeline);
		add_to_map(job_init_map, WORD, job_add_process);
	}
	return (job_init_map);
}
