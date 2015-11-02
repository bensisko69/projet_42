/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_es.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 17:17:40 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/22 17:17:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print[] = {{'%', print_p100}, {'c', print_c}, {'s', print_s}, 
			{'d', print_d_es}, {'x', print_x}, {'o', print_o}, {'i', print_d_es},
			{'X', print_X_MAJ}, {'D', print_d_l}, {'p', print_p}, {'O', print_o_l},
			{'u', print_u}, {'U', print_u_l}, {'C', print_c_maj}};

		a = 0;
		while (a++ < sizeof(tab_print) / sizeof(t_print))
		{
			if (tab_print[a - 1].c == format[(*i)])
				ret = tab_print[a - 1].func(list, nbr);	
		}
		return (ret);
}

static int	print_e(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print[] = {{'%', print_p100}, {'c', print_c}, {'s', print_s}, 
			{'d', print_d_es_0}, {'x', print_x}, {'o', print_o}, {'i', print_d_es_0},
			{'X', print_X_MAJ}, {'D', print_d_l}, {'p', print_p}, {'O', print_o_l},
			{'u', print_u}, {'U', print_u_l}, {'C', print_c_maj}};

		a = 0;
		while (a++ < sizeof(tab_print) / sizeof(t_print))
		{
			if (tab_print[a - 1].c == format[(*i)])
				ret = tab_print[a - 1].func(list, nbr);	
		}
		return (ret);
}

int	print_es(const char *format, int *i, va_list list)
{
	int	nb;
	int	ret;

	ret = 0;
	(*i)++;
	if (format[(*i)] == '0')
	{
		nb = ft_atoi(nbr(format, i));
		ret += print_e(format, i, list, nb);
	}
	else if (format[(*i)] == '+')
		ret += print_ps(format, i, list);
	else
	{
		nb = ft_atoi(nbr(format, i));
		ret += print(format, i, list, nb);
	}
	return(ret);
}