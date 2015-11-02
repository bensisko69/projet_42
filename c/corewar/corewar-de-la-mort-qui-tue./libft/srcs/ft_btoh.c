/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 23:46:54 by mschuck           #+#    #+#             */
/*   Updated: 2014/02/27 23:55:21 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_btoh(char *bin)
{
	char	*res;
	int		i;

	if (bin == NULL)
		return (NULL);
	i = ft_btoi(bin);
	res = ft_itoh(i);
	return (res);
}
