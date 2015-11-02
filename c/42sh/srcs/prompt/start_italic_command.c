/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_italic_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:12:38 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 11:21:02 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*start_italic_command(t_context *context, size_t n)
{
	UNUSED(n);
	UNUSED(context);
	return (ft_strdup(START_ITALIC));
}
