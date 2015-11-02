/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/06 22:31:42 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 22:35:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_word(const char *str)
{
	int	i;
	int	size;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'l')
				i = i + 2;
			else
				i = i + 1;
		}
		else
		{
			size++;
			i++;
		}
	}
	return (size);
}

static void	search_char(const char *format, int *i)
{
	while (format[(*i)] != '%' && format[(*i)])
	{
		write(1, &format[(*i)], 1);
		(*i)++;
	}
}

static int	search_l(const char *format, int *i, va_list list)
{
	if (format[(*i)] == 'l')
	{
		(*i)++;
		return (print_l(format[(*i)], list));
	}
	return (0);
}

int			ft_printf(const char *format, ...)
{
	t_func			d_func;
	static t_print	print_tab[] = OPT_FUNC_ARRAY;

	d_func.i = 0;
	va_start(d_func.list, format);
	d_func.size = size_word(format);
	while (format[d_func.i] && (((int)ft_strlen(format)) + 1) >= d_func.i)
	{
		search_char(format, &(d_func.i));
		d_func.i++;
		d_func.a = 0;
		while (d_func.a++ < sizeof(print_tab) / sizeof(t_print))
		{
			if (format[d_func.i] == 'l')
			{
				d_func.size += search_l(format, &(d_func.i), d_func.list);
				break ;
			}
			else if (print_tab[d_func.a - 1].c == format[d_func.i])
				d_func.size += print_tab[d_func.a - 1].func(d_func.list);
		}
		d_func.i++;
	}
	va_end(d_func.list);
	return (d_func.size);
}
