/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_italic_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 11:12:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 11:24:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*end_italic_command(t_context *context, size_t n)
{
	UNUSED(n);
	UNUSED(context);
	return (ft_strdup(END_ITALIC));
}
