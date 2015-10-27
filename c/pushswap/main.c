/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/10 16:04:11 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 19:32:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push(int dt, t_list **liste, int fst)
{
	t_list	*new;

	if (!(*liste))
	{
		(*liste) = new_link(dt, NULL, NULL, TRUE);
		(*liste)->next = (*liste);
		(*liste)->previous = (*liste);
	}
	else
	{
		new = new_link(dt, (*liste)->previous, (*liste), fst);
		(*liste)->previous->next = new;
		(*liste)->previous = new;
		if (fst == TRUE)
		{
			(*liste)->fst = FALSE;
			(*liste)->previous->fst = TRUE;
			(*liste) = (*liste)->previous;
		}
	}
}

t_list			*new_link(int dt, t_list *previous, t_list *next, int fst)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		new->dt = dt;
		new->fst = fst;
		new->previous = previous;
		new->next = next;
	}
	return (new);
}

void			print_list(t_list *list)
{
	int		i;

	i = 0;
	if (!list)
	{
		ft_putstr(GREEN);
		ft_putstr_fd("LIST EMPTY", 2);
		ft_putstr(DEFAULT);
	}
	while (list && list->fst != TRUE)
		list = list->next;
	while (list && (list->fst == FALSE || !i++))
	{
		write(1, "[", 1);
		ft_putnbr(list->dt);
		write(1, "]", 1);
		list = list->next;
	}
	write(1, "\n", 1);
}

static int		cmp(char **str)
{
	int	b;
	int	i;

	i = 1;
	b = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "-v") == 0)
			b = 1;
		i++;
	}
	return (b);
}

int				main(int ac, char **av)
{
	t_list	*l_a;
	t_list	*l_b;
	int		a;
	int		nbr;
	int		b;

	l_a = NULL;
	l_b = NULL;
	a = 1;
	b = 0;
	if (ac > 1)
	{
		if (check(av) == 1)
			return (1);
		b = cmp(av);
		while (--ac > b)
		{
			nbr = ft_atoi(av[a]);
			push(nbr, &l_a, FALSE);
			a++;
		}
		push_swap(&l_a, &l_b, b);
	}
	write (1, "\n", 1);
	return (0);
}
