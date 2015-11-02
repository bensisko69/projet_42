/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschuck <mschuck@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/17 10:10:47 by mschuck           #+#    #+#             */
/*   Updated: 2014/09/06 07:51:10 by mschuck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*two_byte(int num, char **str)
{
	char	*s;

	s = *str;
	s[0] = '0';
	if (num < 10)
		s[1] = '0' + num;
	else
		s[1] = (char)(87 + num);
	return (s);
}

static void	store(int **r, int *i, unsigned int num)
{
	int		*rem;

	rem = *r;
	while (num > 0)
	{
		rem[*i] = num % 16;
		num = num / 16;
		*i = *i + 1;
	}
}

char		*ft_itohlong(unsigned long num)
{
	int		i;
	int		j;
	char	*s;
	int		*rem;

	if ((s = ft_strnew(24)) == NULL)
		return (NULL);
	if ((int)num > -1 && num < 16)
		return (two_byte(num, &s));
	if ((rem = ft_memalloc(sizeof(int) * 16)) == NULL)
	{
		ft_memdel((void**)&s);
		return (NULL);
	}
	i = 0;
	j = 0;
	store(&rem, &i, num);
	while (--i > -1)
		s[j++] = (rem[i] > 9) ? (char)(rem[i] + 87) : (char)(rem[i] + '0');
	s[j] = '\0';
	ft_memdel((void**)&rem);
	return (s);
}
