/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/30 16:34:05 by lrenoud-         ###   ########.fr       */
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
*/

#ifndef LEMIN_H
# define LEMIN_H
# define FALSE 1
# define TRUE 0
# define OPEN_FALED "Open faled"
# define PARSE_ERROR "Parse error"
# define NAME_ERROR "Two name of room"
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct s_liste	t_liste;

struct					s_liste
{
	unsigned int		start;
	unsigned int		type;
	char				*name_room;
	char				*str;
	int					nbr_ants;
	t_liste				*next;
	t_liste				*previous;
}						;

void					ft_error(int nbr, char *str);

t_liste					*create_ellem(char *line);
void					ft_liste_push(char *line, t_liste **list);
void					print_liste(t_liste *list);

int						parse(t_liste **list);
int						parse_exp(t_liste **list);
int						parse_com(t_liste **list);
int						parse_nbr(t_liste **liste);
int						parse_name_room(t_liste **liste);
int						parse_cmd(t_liste **liste);
int						parse_noeud(t_liste **liste);

int						lexer(t_liste **liste);
int						check_name_room(t_liste **liste);
int						cmp(t_liste *list);

#endif
