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

# define OPT3 {'b', print_b}
# define OPT2 {'i', print_d}, {'u', print_u}, {'X', print_x_maj}, OPT3
# define OPT1 {'p', print_p}, {'x', print_x}, {'o', print_o}, OPT2
# define OPT_FUNC_ARRAY {{'s', print_s}, {'d', print_d}, {'c', print_c}, OPT1}

# define PRINT_L1 {'u', print_lu}, {'X', print_lx_maj}
# define PRINT_L {{'d', print_ld}, {'x', print_lx}, {'o', print_lo}, PRINT_L1}

# include <stdarg.h>
# include <unistd.h>
# include "../includes/libft.h"

typedef int(*t_f_print)(va_list);
typedef struct s_print	t_print;
typedef struct s_func	t_func;

struct					s_func
{
	int					i;
	int					size;
	unsigned int		a;
	va_list				list;
}						;

struct					s_print
{
	char				c;
	t_f_print			func;
}						;

int						ft_printf(const char *format, ...);
int						print_po(va_list list);
int						print_s(va_list list);
int						print_d(va_list list);
int						print_c(va_list list);
int						print_p(va_list list);
int						print_x_maj(va_list list);
int						print_x(va_list list);
int						print_o(va_list list);
int						print_u(va_list list);
int						print_b(va_list list);
int						print_ld(va_list list);
int						print_lx(va_list list);
int						print_lo(va_list list);
int						print_lu(va_list list);
int						print_lx_maj(va_list list);
int						print_l(char c, va_list list);
int						ft_putnbr_base_long(long nb, char *base, int l);
int						ft_putnbr_unsigned_long(unsigned long int nb, int l);
int						ft_putnbr_long(long nb, int l);
int						ft_putnbr_base(size_t nb, char *base, int l);
int						ft_putnbr_unsigned(unsigned nb, int l);
int						put_adress(void const *p);

#endif
