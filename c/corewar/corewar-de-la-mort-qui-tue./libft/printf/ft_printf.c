/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/12 14:52:39 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:47:21 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		ft_tab(va_list var, char *fl)
{
	int			i;
	int			j;
	static t_ft tab[] = {

	{"c", ft_printf_c}, {"s", ft_printf_s}, {"p", ft_printf_p},
	{"d", ft_printf_d}, {"i", ft_printf_d}, {"o", ft_printf_o},
	{"x", ft_printf_x}, {"X", ft_printf_mx}, {"b", ft_printf_b},
	{"u", ft_printf_u}, {"ld", ft_printf_ld}, {"lx", ft_printf_lx},
	{"lX", ft_printf_lmx}, {"lo", ft_printf_lo}, {"cc", ft_printf_cc},
	{"cv", ft_printf_cv}, {"cj", ft_printf_cj}, {"cr", ft_printf_cr},
	{"cp", ft_printf_cp}, {"%", ft_printf_pc}, {0, NULL}
	};
	i = 0;
	j = 0;
	while (tab[i].ft != NULL)
	{
		if (ft_strcmp_printf(tab[i].fl, fl) == 0)
			j += tab[i].ft(var);
		i++;
	}
	ft_putstr_printf(DEFAULT);
	return (j);
}

static int		ft_check(char c)
{
	char	*fl;
	int		i;

	fl = "lcuspdirvjpcboxX%";
	i = 0;
	while (fl[i] != '\0')
	{
		if (c == fl[i])
			return (1);
		i++;
	}
	return (0);
}

static int		ft_fl(const char *format, int *i, int *ret, va_list var)
{
	const char	*s;
	const char	*e;
	char		*fl;
	int			len;

	fl = NULL;
	s = (format + *i + 1);
	e = s;
	len = 0;
	while (ft_check(*e))
		e++;
	len = e - s;
	fl = malloc(sizeof(char) * (len + 1));
	fl = ft_strncpy_printf(fl, s, len);
	*ret += ft_tab(var, fl);
	free(fl);
	*i += len;
	return (*ret);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	int			ret;
	va_list		var;

	i = 0;
	ret = 0;
	va_start(var, format);
	while (format[i])
	{
		if (format[i] == '%')
			ft_fl(format, &i, &ret, var);
		else
		{
			write(1, &format[i], 1);
			ret++;
		}
		i++;
	}
	va_end(var);
	return (ret);
}
