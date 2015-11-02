/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 12:12:45 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 13:06:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		c;
	char	leng;
	char	*chaine;

	if (s == NULL)
		return (NULL);
	leng = ft_strlen(s) + 1;
	chaine = malloc(leng * sizeof(*chaine));
	c = 0;
	if (chaine == 0)
		return (chaine);
	while (s[c] != '\0')
	{
		chaine[c] = f(s[c]);
		c++;
	}
	chaine[c] = '\0';
	return (chaine);
}
