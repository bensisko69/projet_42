/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 10:52:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/21 10:52:51 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int print(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print_0[] = {{'%', print_p100_0}, {'c', print_c_0}, {'s', print_s_0}, 
			{'d', print_d_0}, {'x', print_x_0}, {'o', print_o_0}, {'i', print_d_0},
			{'X', print_X_MAJ_0}, {'D',print_d_l_0}, {'O', print_o_l_0}, 
			{'u', print_u_0}, {'U', print_u_l_0}, {'p', print_p_0}, 
			{'C', print_c_maj_0}};

	ret = 0;
	a = 0;
	while (a++ < sizeof(tab_print_0) / sizeof(t_print))
	{
		if (tab_print_0[a - 1].c == format[(*i)])
			ret += tab_print_0[a - 1].func(list, nbr);
	}
	// (*i)++;
	return (ret);
}

int	print_0(const char *format, int *i, va_list list)
{
	int nb;

	(*i)++;
	nb = ft_atoi(nbr(format, i));
	return (print(format, i, list, nb));
}