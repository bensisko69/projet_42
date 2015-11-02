/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_status_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:16:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 14:35:17 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*last_status_command(t_context *context, size_t n)
{
	UNUSED(n);
	return (ft_itoa(context->last_status));
}
