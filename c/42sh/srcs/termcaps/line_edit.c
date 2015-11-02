/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_edit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 00:32:05 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 18:55:12 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void		line_insert(t_line_edit *le, char *str, size_t len)
{
	if (le->len + len < LINE_BUFF_SIZE)
	{
		ft_memmove(le->line + le->pos + len,
					le->line + le->pos,
					le->len - le->pos);
		ft_strncpy(le->line + le->pos, str, len);
		le->pos += len;
		le->len += len;
		term_command(CAP_INSERT_MODE);
		write(tty_fd(), str, len);
		term_command(CAP_END_INSERT);
	}
}

void		line_remove(t_line_edit *le, size_t len)
{
	ft_memmove(le->line + le->pos,
				le->line + le->pos + len,
				le->len - le->pos - len);
	le->len -= len;
	ft_bzero(le->line + le->len, len);
	term_command_n(CAP_DEL_ONE_CHAR, len);
}
