/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:02:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/28 16:36:01 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* type dans la structure.
** 1 type NBR
** 2 type ROOM
** 3 type start
** 4 type end
** 5 type COMMENT
** 6 type TUBE
*/

/* start
** 1 = 1er ellem
** 0 = ellem suivant
*/

#ifndef LEMIN_H
# define LEMIN_H
# define FALSE 1
# define TRUE 0
# define OPEN_FALED "Open faled"
# include <stdlib.h>
# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct s_liste	t_liste;

struct				s_liste
{
	unsigned int	start;
	unsigned int	type;
	char			*name_room;
	char			*str;
	t_liste			*next;
	t_liste			*previous;
}					;

void				ft_error(int nbr);

t_liste		*create_ellem(char *line);
void		ft_liste_push(char *line, t_liste **list);
void		print_liste(t_liste *list);

int			parse(t_liste **list);
int			parse_exp(t_liste **list);
int			parse_com(t_liste **list);
int			parse_nbr(t_liste **liste);

#endif // LEMIN_H
