/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_underline_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 16:14:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 14:33:08 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*start_underline_command(t_context *context, size_t n)
{
	UNUSED(n);
	UNUSED(context);
	return (ft_strdup(START_UNDERLINE));
}
