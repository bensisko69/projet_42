/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:19:09 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/02/04 16:19:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print[] = {{'%', print_p100}, {'c', print_c}, {'s', print_s}, 
			{'d', print_d_ps}, {'x', print_x}, {'o', print_o}, {'i', print_d_ps},
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

static int	print_es_0(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print[] = {{'%', print_p100}, {'c', print_c}, {'s', print_s}, 
			{'d', print_d_ps_0}, {'x', print_x}, {'o', print_o}, {'i', print_d_ps_0},
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

int	print_ps(const char *format, int *i, va_list list)
{
	int	nb;
	int	ret;

	ret = 0;
	(*i)++;
	if (format[(*i)] == '0')
	{
		nb = ft_atoi(nbr(format, i));
		ret += print_es_0(format, i, list, nb);
	}
	else if (format[(*i)] == ' ')
	{
		(*i)++;
		nb = ft_atoi(nbr(format, i));
		ret += print(format, i, list, nb);
	}
	else
	{
		nb = ft_atoi(nbr(format, i));
		ret += print(format, i, list, nb);
	}
	return(ret);
}