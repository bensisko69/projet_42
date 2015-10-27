/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:32:36 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/15 18:23:10 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void				ft_execve(char *cmd, char **argum, t_list *list)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, 0, 0);
	}
	if (pid == 0)
	{
		execve(cmd, argum, change(list));
		ft_putendl("error execve");
		exit(0);
	}
}

static void			exec_absolu(char *line, t_list *list)
{
	char	**str;

	str = ft_strsplit(line, ' ');
	if (check_cmd(str[0]))
		ft_execve(str[0], str, list);
	else
		ft_erreur(line, ERR_NO_SUCH_FILE, 0);
	free_char_array(str);
}

static t_list		*ft(t_list *lst)
{
	static t_list	*save = NULL;

	if (save == NULL)
		save = lst;
	return (save);
}

static void			ft_signal(int sig)
{
	t_list	*list;

	if (sig == 3)
		exit(0);
	list = ft(NULL);
	ft_putchar('\n');
	show_prompt(list);
}

int					main(int ac, char **av, char **env)
{
	char	*line2;
	t_e		e;

	(void)ac;
	(void)av;
	e.list = ft_env_cpy(env);
	signal(SIGQUIT, ft_signal);
	show_prompt(e.list);
	while (get_next_line(0, &(e.line)) == 1)
	{
		line2 = exange_tab_or_space(e.line);
		e.args = ft_strsplit(line2, ' ');
		if (e.args && e.args[0])
		{
			if (ft_strchr(e.args[0], '/'))
				exec_absolu(e.line, e.list);
			else
				do_command(&(e.list), e.line);
		}
		free(e.line);
		show_prompt(e.list);
		free_char_array(e.args);
	}
	ft_putchar('\n');
	return (0);
}
