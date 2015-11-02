/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 02:01:34 by mschuck           #+#    #+#             */
/*   Updated: 2013/12/16 14:30:54 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_word(int k, int pass, int neg)
{
	char	*w;

	if ((w = ft_strnew(pass + 1)) == NULL)
		return (NULL);
	ft_bzero(w, pass + 1);
	while (pass--)
	{
		w[pass] = '0' + (char)(k % 10);
		k /= 10;
	}
	w[0] = (neg ? '-' : w[0]);
	return (w);
}

char		*ft_itoa(int n)
{
	int	k;
	int	pass;
	int	neg;

	neg = 0;
	pass = 0;
	if (n == 0)
		return (ft_strdup("0"));
	else if (n < 0)
	{
		pass++;
		n = -n;
		neg = 1;
	}
	k = n;
	while (n)
	{
		pass++;
		n /= 10;
	}
	return (make_word(k, pass, neg));
}
