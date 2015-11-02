/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 22:48:21 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/17 21:04:06 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"
#include "environ.h"
#include "tools.h"

char			*n_last_directories(const char *dir, size_t n)
{
	size_t		len;
	const char	*end;

	len = ft_strlen(dir);
	end = dir + len;
	while (end != dir)
	{
		if (*end == '/' && !--n)
		{
			++end;
			break ;
		}
		--end;
	}
	return (ft_strsub(end, 0, dir + len - end));
}

char			*replace_home(const char *str, const char *home)
{
	if (ft_strstr(str, home) == str)
		return (str_replace(str, home, HOME_SHORTCUT_STR));
	return (ft_strdup(str));
}

char			*path_command(t_context *context, size_t n)
{
	char		*pwd;
	char		*home;
	char		*trimmed;

	pwd = environ_get(context, VAR_PWD);
	home = environ_get(context, VAR_HOME);
	if (!pwd)
		return (ft_strdup(NO_PWD));
	pwd = (home ? replace_home(pwd, home) : ft_strdup(pwd));
	if (!n)
		return (pwd);
	trimmed = n_last_directories(pwd, n);
	free(pwd);
	return (trimmed);
}
