/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbudin <mbudin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:44:45 by mbudin            #+#    #+#             */
/*   Updated: 2014/10/31 17:34:45 by mbudin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_putstr_printf(char const *str)
{
	int		i;

	i = ft_strlen_printf(str);
	write(1, str, i);
	return (i);
}
