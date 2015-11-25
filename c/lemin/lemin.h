/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/25 15:08:33 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* type dans la structure.
** 1 type NBR
** 2 type ROOM
** 3 type start
** 4 type end
** 6 type TUBE
** start
** 1 = 1er ellem
** 0 = ellem suivant
** room
** 0 autre
** 1 start
** 2 end
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
}						;

struct					s_map
{
	int			nb_ants;
	t_list		*rooms;
	t_list		*noeuds;
};

t_room					*struct_room(int type, t_list **liste);
t_noeud					*struct_noeud(t_list **liste);

int						parse(t_list **liste, t_map *map);
int						parse_exp(t_list **liste, t_map *map);
int						parse_nbr(t_list **liste, t_map *map);
int						parse_room(t_list **liste,t_map *map);
int						parse_name_room(t_list **liste);
int						parse_cmd(t_list **liste, t_map *map);
int						parse_noeud(t_list **liste, t_map *map);

int						lexer(t_list **liste);
int						check_name_room(t_list **liste);
int						check_noeud(t_list **liste);
int						double_name(t_list **liste);
int						check_name_noeud(t_list **liste);

void					print(t_map *map);

#endif
