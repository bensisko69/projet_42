/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 15:18:45 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/27 13:18:23 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

# include "libft.h"

/*
** Generic path joining function
*/
char		*path_join(const char *head, const char *tail);

/*
** Char array utilities
*/
typedef unsigned long long	(*t_char_array_functor)(const char *);
size_t		char_array_map(char **array, t_char_array_functor functor);
size_t		char_array_size(char **array);
void		char_array_free(char **array);

/*
** File stats
*/
typedef struct stat		t_stat;
int			is_file(const char *path);
int			is_dir(const char *path);

/*
** Generic string replace function
*/
char		*str_replace(const char *str, const char *find, const char *rep);

/*
** Generic list joining function
*/
char		*join_str_list(t_list *str_list, char c);

#endif
