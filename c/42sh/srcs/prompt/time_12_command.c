/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_12_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:39:19 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/23 02:17:51 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "prompt.h"
#include "environ.h"

char			*time_12_command(t_context *context, size_t n)
{
	time_t		now;
	char		time_string[128];
	struct tm	*date;

	UNUSED(n);
	UNUSED(context);
	time(&now);
	date = localtime(&now);
	strftime(time_string, 128, "%r", date);
	return (ft_strdup(time_string));
}
