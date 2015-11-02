/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_l2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/26 12:37:15 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/26 12:37:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_lx_maj(va_list list)
{
	long	nb;

	nb = va_arg(list, long);
	return (ft_putnbr_base_long(nb, "0123456789ABCDEF", 0));
}
