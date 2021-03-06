/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 14:54:18 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/03/15 18:24:01 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# define BUFF_SIZE 32
# include <string.h>
# include "libft/includes/libft.h"
# define TAB3 ,{BUILTIN_CD, ft_cd}}
# define TAB2 {BUILTIN_SETENV, ft_setenv},{BUILTIN_UNSETENV, ft_unsetenv} TAB3
# define TAB {{BUILTIN_ENV, print_list},{BUILTIN_EXIT, ft_exit}, TAB2

typedef struct s_list		t_list;
typedef struct s_builtins	t_builtins;

typedef struct stat			t_stat;
typedef struct s_e			t_e;

typedef void				(*t_command)(t_list**, char*);

struct			s_e
{
	t_list		*list;
	char		**args;
	char		*line;
};

struct			s_list
{
	char		*str;
	t_list		*next;
};

struct			s_builtins
{
	char		*str;
	t_command	func;
};

t_list			*ft_env_cpy(char **env);
void			ft_link(t_list **line, char *str);
char			**change(t_list *list);
void			ft_access(t_list *list, char *line);
char			*join(char *str1, char *carac, char *str2);
void			free_char_array(char **array);
void			exchange_content(t_list *list, char *cmp2, char *cmp3);
void			ft_execve(char *cmp, char **argum, t_list *list);
char			*search(t_list *list, char *var_name);
int				char_array_size(char **str);
void			list_remove(t_list **list, char *str);
void			ft_oldpwd(t_list **list, char *name_src, char *name_dest);
void			do_command(t_list **list, char *line);
int				check_cmd(char *cmd);
void			show_prompt(t_list *list);
int				ft_strlen_char(char *str, char symb);
char			*exange_tab_or_space(char *line);

# define BUILTIN_ENV		"env"

void			print_list(t_list **list, char *line);
# define BUILTIN_EXIT		"exit"
# define BUILTIN_SETENV		"setenv"

void			ft_setenv(t_list **list, char *line);
# define BUILTIN_UNSETENV	"unsetenv"

void			ft_unsetenv(t_list **list, char *line);
# define BUILTIN_CD			"cd"

void			ft_cd(t_list **list, char *line);

# define ERR_CMD_NOT_FOUND		"command not found"
# define ERR_NO_SUCH_FILE		"no such file or directory"
# define ERR_DENIED				"permission denied"
# define ERR_NOT_A_DIR			"not a directory"
# define ERR_UNKNOWN			"erreur unknown"
# define ERR_NOT_ENOUGH_ARGS	"not enough arguments"
# define ERR_NON_EXISTING_KEY	"non existing key"

void			ft_erreur(char *cmd, char *erreur, char *info);

#endif
