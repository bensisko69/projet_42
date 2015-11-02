/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:32:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/03/27 13:16:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "builtins.h"
#include "environ.h"
#include "tools.h"

int			ft_chdir(t_context *context, const char *dir)
{
	char	*pwd;
	char	*new_pwd;

	if (access(dir, F_OK) == -1)
		return (builtin_error(CD_BUILTIN, ERR_NO_SUCH_FILE, dir));
	if (access(dir, X_OK) == -1)
		return (builtin_error(CD_BUILTIN, ERR_DENIED, dir));
	pwd = environ_get(context, VAR_PWD);
	pwd = (pwd ? ft_strdup(pwd) : getcwd(0, 0));
	chdir(dir);
	new_pwd = (*dir == '/' ? ft_strdup(dir) : path_join(pwd, dir));
	environ_set(context, VAR_OLDPWD, pwd);
	environ_set(context, VAR_PWD, new_pwd);
	free(new_pwd);
	free(pwd);
	return (BUILTIN_SUCCESS);
}

int			illuminati_cd(t_context *context, t_list *args)
{
	char	*pwd;
	char	*find;
	char	*replace;
	char	*new_pwd;

	find = token_value(args, 2);
	replace = token_value(args, 3);
	pwd = environ_get(context, VAR_PWD);
	if ((new_pwd = str_replace(pwd, find, replace)) == 0)
		return (builtin_error(CD_BUILTIN, ERR_STRING_NOT_IN_PWD, find));
	if (ft_chdir(context, new_pwd) == BUILTIN_SUCCESS)
		ft_putendl(new_pwd);
	free(new_pwd);
	return (BUILTIN_SUCCESS);
}

int			classical_cd(t_context *context, t_list *args)
{
	char	*curpath;
	char	*dir;
	char	*old_pwd;
	int		ret;

	curpath = token_value(args, 2);
	if (curpath[0] == '-' && !curpath[1])
	{
		old_pwd = environ_get(context, VAR_OLDPWD);
		dir = (old_pwd ? ft_strdup(old_pwd) : getcwd(0, 0));
		ft_putendl(dir);
	}
	else if (curpath[0])
		dir = ft_strdup(curpath);
	else
		dir = ft_strdup(".");
	ret = ft_chdir(context, dir);
	free(dir);
	return (ret);
}

int			home_cd(t_context *context)
{
	char	*home_directory;

	home_directory = environ_get(context, VAR_HOME);
	if (home_directory)
		return (ft_chdir(context, home_directory));
	return (builtin_error(CD_BUILTIN, ERR_NO_HOME, 0));
}

int			b_cd(t_context *context, t_list *args)
{
	size_t	nb_args;

	nb_args = ft_lstsize(args);
	if (nb_args == 1)
		return (home_cd(context));
	if (nb_args == 2)
		return (classical_cd(context, args));
	if (nb_args == 3)
		return (illuminati_cd(context, args));
	return (builtin_error(CD_BUILTIN, ERR_TOO_MANY_ARGS, 0));
}
