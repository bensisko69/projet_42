/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/06 22:32:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/27 23:07:11 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <wchar.h>
# include "../includes/libft.h"
#include <limits.h>

typedef int(*t_f_print)(va_list, int);
typedef struct s_print	t_print;

struct					s_print
{
	char				c;
	t_f_print			func;
}						;

int						ft_printf(const char *format, ...);
void					reverse(char *str);
void					ft_putnbr_base(size_t nb, char *base, int i, char *str);
void					ft_putnbr_base_long(long int nb, char *base, int i, char *str);
char					*nbr(const char *format, int *i);
int						print_pos2(char *str, int nbr, char c);
int						print_neg2(char *str, int nbr, char c);

/*
**Option 0
*/
int						print_0(const char *format, int *i, va_list list);
int						print_c_0(va_list list, int nbr);
int						print_p100_0(va_list list, int nbr);
int						print_s_0(va_list list, int nbr);
int						print_d_0(va_list list, int nbr);
int						print_x_0(va_list list, int nbr);
int						print_o_0(va_list list, int nbr);
int						print_X_MAJ_0(va_list list, int nbr);
int						print_d_l_0(va_list list, int nbr);
int						print_o_l_0(va_list list, int nbr);
int						print_u_0(va_list list, int nbr);
int						print_u_l_0(va_list list, int nbr);
int						print_p_0(va_list list, int nbr);
int						print_c_maj_0(va_list list, int nbr);

/*
**Sans 0
*/
int						print_c(va_list list, int nbr);
int						print_p100(va_list list, int nbr);
int						print_s(va_list list, int nbr);
int						print_d(va_list list, int nbr);
int						print_x(va_list list, int nbr);
int						print_o(va_list list, int nbr);
int						print_X_MAJ(va_list list, int nbr);
int						print_d_l(va_list list, int nbr);
int						print_p(va_list list, int nbr);
int						print_o_l(va_list list, int nbr);
int						print_u(va_list list, int nbr);
int						print_u_l(va_list list, int nbr);
int						print_c_maj(va_list list, int nbr);

/*
**avec espace
*/
int						print_es(const char *format, int *i, va_list list);
int						print_d_es(va_list list, int nbr);
int						print_d_es_0(va_list list, int nbr);

/*
**avec +
*/

int						print_ps(const char *format, int *i, va_list list);
int						print_d_ps(va_list list, int nbr);
int						print_d_ps_0(va_list list, int nbr);

/*
**avec -
*/
int						print_ng(const char *format, int *i, va_list list);
int						print_d_ng(va_list list, int nbr);

#endif
