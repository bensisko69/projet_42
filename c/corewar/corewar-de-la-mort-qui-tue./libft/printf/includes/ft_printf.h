/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/12 14:52:42 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:32:57 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define YELLOW			"\033[1;33m"
# define BLUE			"\033[1;34m"
# define PURPLE			"\033[1;35m"
# define CYAN			"\033[1;36m"
# define DEFAULT		"\033[00m"

typedef	struct			s_ft
{
	const char			*fl;
	int					(*ft)(va_list);
}						t_ft;

int						ft_printf(const char *format, ...);
int						ft_printf_c(va_list var);
int						ft_printf_s(va_list var);
int						ft_printf_p(va_list var);
int						ft_printf_d(va_list var);
int						ft_printf_o(va_list var);
int						ft_printf_x(va_list var);
int						ft_printf_mx(va_list var);
int						ft_printf_b(va_list var);
int						ft_printf_u(va_list var);
int						ft_printf_ld(va_list var);
int						ft_printf_lx(va_list var);
int						ft_printf_lmx(va_list var);
int						ft_printf_lo(va_list var);
int						ft_printf_cr(va_list var);
int						ft_printf_cv(va_list var);
int						ft_printf_cj(va_list var);
int						ft_printf_cc(va_list var);
int						ft_printf_cp(va_list var);
int						ft_printf_pc(va_list var);
int						ft_putchar_printf(char c);
int						ft_putnbr_printf(int n);
int						ft_putlongnbr(long int n);
unsigned int			ft_putnbr_base_printf(unsigned int nbr, char *base);
unsigned long int		ft_putunslongint_base(unsigned long int n, char *base);
int						ft_putstr_printf(char const *str);
int						ft_putstr_color(char const *str);
int						ft_strlen_printf(const char *str);
int						ft_putadd(void const *p);
int						ft_put_unicorn(void);
int						ft_strcmp_printf(const char *s1, const char *s2);
char					*ft_strncpy_printf(char *s1, const char *s2, size_t n);
unsigned int			ft_putnbr_base_p(size_t nbr, char *base);

#endif
