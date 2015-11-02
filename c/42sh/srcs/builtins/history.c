/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 22:02:47 by kpoirier          #+#    #+#             */
/*   Updated: 2014/03/27 13:45:36 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "termcaps.h"

void				history_add(t_context *context, const char *command_line)
{
	static size_t	entry_number = 1;
	t_history		new_entry;
	t_dlist			*new_link;

	if (*command_line != '\0')
	{
		new_entry.entry_number = entry_number;
		new_entry.entry = ft_strdup(command_line);
		new_link = ft_dlist_new(&new_entry, sizeof(t_history));
		ft_dlist_append(&context->history, new_link);
		++entry_number;
	}
}

void				free_history(void *p_history, size_t size)
{
	t_history		*history;

	UNUSED(size);
	history = (t_history *)p_history;
	free(history->entry);
	free(history);
}

static void			display_one_entry(t_history *entry)
{
	WRITE(tty_fd(), "\t");
	ft_putnbr_fd(entry->entry_number, tty_fd());
	WRITE(tty_fd(), "\t");
	ft_putendl_fd(entry->entry, tty_fd());
}

static int			history_display(t_context *context, int start, int end)
{
	t_dlist			*history;
	size_t			i;
	size_t			j;
	size_t			f;

	i = (end ? end - start : BASE_HISTORY_DISPLAY);
	f = 0;
	j = i;
	history = context->history;
	if (history)
	{
		while (((t_history*)(history->next->content))->entry_number > 1)
			history = history->next;
		while (j-- && ((t_history*)(history->content))->entry_number > 1)
			history = history->previous;
		j = i;
		while (j && (((t_history*)(history->content))->entry_number > 1 || !f))
		{
			display_one_entry((t_history*)(history->content));
			history = history->next;
			++f;
			--j;
		}
	}
	return (BUILTIN_SUCCESS);
}

int					b_history(t_context *context, t_list *args)
{
	size_t			arg_count;

	arg_count = ft_lstsize(args);
	if (arg_count > 3)
		return (builtin_error(HISTORY_BUILTIN, ERR_TOO_MANY_ARGS, 0));
	if (arg_count == 1)
		return (history_display(context, 0, 0));
	return (BUILTIN_SUCCESS);
}
