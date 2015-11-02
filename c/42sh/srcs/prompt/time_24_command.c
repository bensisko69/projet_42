/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_24_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/18 17:39:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/18 18:38:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "prompt.h"
#include "environ.h"

char	*time_24_command(t_context *context, size_t n)
{
	time_t	now;
	char	*time_string;

	UNUSED(n);
	UNUSED(context);
	now = time(0);
	time_string = ctime(&now);
	return (ft_strsub(time_string, 11, 8));
}
