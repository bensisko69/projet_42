/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_number_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 15:28:00 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/19 14:34:22 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*jobs_number_command(t_context *context, size_t n)
{
	UNUSED(n);
	return (ft_itoa(ft_lstsize(context->jobs)));
}
