/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 15:24:01 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 19:33:11 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PUSH_SWAP_H
# define _PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define DEFAULT "\033[00m"

typedef struct		s_list
{
	int				dt;
	int				fst;
	struct s_list	*next;
	struct s_list	*previous;

}					t_list;

t_list				*new_link(int dt, t_list *previous, t_list *next, int fst);
void				push(int dt, t_list **liste, int first);

void				ra(t_list **l_a, char *func);
void				rr(t_list **l_a, t_list **l_b);
void				rra(t_list **l_a, char *func);
void				rrr(t_list **l_a, t_list **l_b);

void				push_a_in_b(t_list **l_a, t_list **l_b, char *func);
void				delete(t_list **link);
void				push_link(t_list *link, t_list **liste, int first);

void				push_swap(t_list **l_a, t_list **l_b, int b);
int					size_list(t_list *l_a);
void				print_list(t_list *list);

int					check(char **tab);

#endif
