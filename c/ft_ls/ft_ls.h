/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@stduent.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:18:11 by lrenoud-          #+#    #+#             */
/*   Updated: 2013/11/28 17:18:55 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "ft_ls.h"
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"

typedef struct stat t_stat;

typedef struct			s_link
{
	char				*element;
	struct s_link		*next;
}						t_link;

typedef int (*t_cmp)(const char *, const char *);

int			ft_ls(void);
int			ft_a(void);
t_link		*ft_new_link(const char *str);
void		ft_add_start(t_link **list,const char *str);
char		*ft_permission(t_stat *cp);
char		ft_type(t_stat *cp);
void		ft_insert(t_link **list, const char *str, t_cmp cmp);
int			ft_r(void);

#endif
