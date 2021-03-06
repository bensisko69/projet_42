/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/12/04 15:46:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** type dans la structure.
** 2 type ROOM
** 3 type start
** 4 type end
*/

#ifndef LEMIN_H
# define LEMIN_H
# define FALSE 1
# define TRUE 0

# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct s_map	t_map;
typedef struct s_room	t_room;
typedef struct s_noeud	t_noeud;
typedef struct s_lab	t_lab;

struct					s_lab
{
	char				*name;
}						;

struct					s_noeud
{
	char				*name_left;
	char				*name_right;
}						;

struct					s_room
{
	int					type_room;
	char				*name;
	int					x;
	int					y;
	t_list				*lab;
}						;

struct					s_map
{
	int			nb_ants;
	t_list		*rooms;
	t_list		*noeuds;
}						;

/*
**lemin.c
*/
char					*delete_tab_or_spaces(char *str);

/*
**parse.c
*/
int						parse(t_list *liste, t_map *map);
int						parse_exp(t_list **liste, t_map *map);
int						parse_room(t_list **liste,t_map *map);
int						parse_tube(t_list **liste,t_map *map);
int						parse_nbr(t_list **liste, t_map *map);

/*
**parse2.c
*/
t_noeud					*struct_noeud(t_list **liste);
int						parse_noeud(t_list **liste, t_map *map);
t_room					*struct_room(int type, t_list **liste);
t_room					*struct_cmd(int type, t_list **liste);
int						parse_cmd(t_list **liste, t_map *map);
int						parse_name_room(t_list **liste, t_map *map);

/*
**lexer.c
*/
int						lexer(t_map *map, t_list **list);
int						check_name_room(t_list *rooms);
int						check_name_noeud(t_map *map);
int						check_cmd(t_list *rooms);

/*
**Print.c
*/
void					print(t_map *map);


/*
**free.c
*/
void					free_tab(char **tab);
void					free_map(t_map *map);
void					free_noeud(t_list *noeud);
void					free_room(t_list *room);
void					free_list(t_list *list);

/*
**labyrinth.c
*/
void					labyrinth(t_map *map);
void					created_lab(t_list *noeuds, t_list *rooms);
t_lab					*struct_lab(char *str);

#endif
