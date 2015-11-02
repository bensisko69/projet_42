/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 18:18:52 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/01/20 18:18:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	search_char(const char *format, int *i)
{
	int	a;

	a = 0;
	while (format[(*i)] != '%' && format[(*i)])
	{
		write(1, &format[(*i)], 1);
		a++;
		(*i)++;
	}
	return (a);
}

static int	print(const char *format, int *i, va_list list, int nbr)
{
	int				ret;
	unsigned int	a;
	static t_print	tab_print[] = {{'%', print_p100}, {'c', print_c}, {'s', print_s}, 
			{'d', print_d}, {'x', print_x}, {'o', print_o}, {'i', print_d},
			{'X', print_X_MAJ}, {'D', print_d_l}, {'p', print_p}, {'O', print_o_l},
			{'u', print_u}, {'U', print_u_l}, {'C', print_c_maj}};

	a = 0;
	while (a++ < sizeof(tab_print) / sizeof(t_print))
	{
		if (tab_print[a - 1].c == format[(*i)])
			ret = tab_print[a - 1].func(list, nbr);	
	}
	// (*i)++;
	return (ret);
}

char	*nbr(const char *format, int *i)
{
	int	b;
	char *nbr;
	int	c;

	c = 0;
	b = (*i);
	while ((format[(*i)] >='0' && format[(*i)] <= '9') && format[(*i)])
		(*i)++;
	nbr = (char *)malloc(sizeof(char) * ((*i) - b) + 1);
	if (nbr == NULL)
		return (NULL);
	while (b < (*i))
	{
		nbr[c] = format[b];
		b++;
		c++;
	}
	nbr[b] = '\0';
	return (nbr);
}

int		ft_printf(const char *format, ...)
{
	int				i;
	va_list			list;
	int				size;
	int				nb;

	nb = 0;
	size = 0;
	i = 0;
	va_start(list, format);
	while (format[i])
	{
		size += search_char(format, &i);
		if(format[i] == '\0')
			return (size);
		i++;
		if (format[i] == '0')
			size += print_0(format, &i, list);
		else if (format[i] == ' ')
			size += print_es(format, &i, list);
		else if (format[i] == '+')
			size += print_ps(format, &i, list);
		else if (format[i] == '-')
			size += print_ng(format, &i, list);
		else
		{
			if(format[i] == '\0')
				return (size);
			nb = ft_atoi(nbr(format, &i));
			size += print(format, &i, list, nb);
		}
		i++;
	}
	va_end(list);
	return (size);
}

int	main(void)
{
	// char c;
	// int	i;

	// // d = -12000000;
	// c = 'D';
	# define ARGS "{%+3d}", -2

	printf("{%d}", ft_printf(ARGS));
	printf("{%d}", printf(ARGS));
	return(0);

}

