/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_underline_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:15:06 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 14:32:36 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*end_underline_command(t_context *context, size_t n)
{
	UNUSED(n);
	UNUSED(context);
	return (ft_strdup(END_UNDERLINE));
}
