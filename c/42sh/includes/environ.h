/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudepard <gudepard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 13:46:11 by gudepard          #+#    #+#             */
/*   Updated: 2014/03/26 18:32:44 by gudepard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRON_H
# define ENVIRON_H

# include "sh.h"

/*
** Common variable names
*/
# define VAR_PWD				"PWD"
# define VAR_OLDPWD				"OLDPWD"
# define VAR_HOME				"HOME"
# define VAR_PATH				"PATH"
# define VAR_SHELL_LVL			"SHLVL"
# define VAR_USER				"USER"
# define VAR_TERM				"TERM"

/*
** Format
*/
# define ENVIRON_VAR_SEPARATOR	'='

/*
** Initialisation function which will copy the system's char **environ and store
** it in the <vars> hashmap
*/
void		environ_init(t_env_vars *vars);
/*
** Clears the hashmap
** Remember that both fields of the entry are dynamically allocated
*/
void		environ_delete(t_env_vars *vars);

/*
** Environment modifications
** For environment variables, we will use 'key' to refer to the name of a
** variable and 'value' for its value
*/
char		*environ_get(t_context *context, const char *key);
void		environ_set(t_context *context, const char *key, const char *value);
void		environ_remove(t_context *context, const char *key);

/*
** Displays the environment variables
*/
void		environ_display(t_env_vars *vars);

/*
** Converts the environ back to a string array
** Essential when providing an environment for the execve system call
*/
char		**environ_array(t_env_vars *vars);

#endif
