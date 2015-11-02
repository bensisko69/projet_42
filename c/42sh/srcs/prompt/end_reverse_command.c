/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_reverse_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/19 15:06:22 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 15:19:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*end_reverse_command(t_context *context, size_t n)
{
	UNUSED(n);
	UNUSED(context);
	return (ft_strdup(END_REVERSE));
}
