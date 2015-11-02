/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_name_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 22:17:40 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/18 15:30:23 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"

char		*user_name_command(t_context *context, size_t n)
{
	char	*user_name;

	UNUSED(n);
	user_name = environ_get(context, VAR_USER);
	if (!user_name)
		user_name = DEFAULT_USER_NAME;
	return (ft_strdup(user_name));
}
