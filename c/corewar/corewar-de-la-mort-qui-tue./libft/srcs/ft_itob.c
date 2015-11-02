/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 23:41:59 by mschuck           #+#    #+#             */
/*   Updated: 2014/02/27 23:42:03 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itob(unsigned int nbr)
{
	char		*ret;
	int			i;
	int			len;

	i = 0;
	len = sizeof(int) * 8;
	ret = NULL;
	if ((ret = ft_strnew(len + 1)) == NULL)
		return (NULL);
	while (--len >= 0)
	{
		ret[i] = '0' + !!(nbr & (1u << len));
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
