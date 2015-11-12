/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/11/12 18:47:43 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* type dans la structure.
** 1 type NBR
** 2 type ROOM
** 3 type start
** 4 type end
** 5 type COMMENT
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
# define OPEN_FALED "Open faled"
# define PARSE_ERROR "Parse error"
# define NAME_ERROR "Two name of room"
# define DOUBLE_NOEUD "Two noeud"
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct s_room	t_room;
typedef struct s_liste	t_liste;
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

struct					s_liste
{
	int					start;
	int					type;
	char				*str;
	int					nbr_ants;
	t_room				room;
	t_noeud				noeud;
	t_liste				*next;
	t_liste				*previous;
}						;

void					ft_error(int nbr, char *str);

t_liste					*create_ellem(char *line);
void					ft_liste_push(char *line, t_liste **list);
void					print_liste(t_liste *list);
void					search_type(t_liste **liste, int type);
void					start_liste(t_liste **liste);
void					init(t_liste **list);
void					init_room(t_liste **list);

int						parse(t_liste **list);
int						parse_exp(t_liste **list);
int						parse_com(t_liste **list);
int						parse_nbr(t_liste **liste);
int						parse_name_room(t_liste **liste);
int						parse_cmd(t_liste **liste);
int						parse_noeud(t_liste **liste);
int						check_list(t_liste **liste);

int						lexer(t_liste **liste);
int						check_name_room(t_liste **liste);
int						check_noeud(t_liste **liste);
int						double_name(t_liste **liste);

//supression de tt les room bug

#endif
