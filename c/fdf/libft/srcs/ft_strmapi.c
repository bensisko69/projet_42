/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 17:16:33 by lrenoud-          #+#    #+#             */
/*   Updated: 2014/10/31 13:06:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int		c;
	char				leng;
	char				*chaine;

	if (s == NULL)
		return (0);
	leng = ft_strlen(s) + 1;
	chaine = malloc(leng * sizeof(*chaine));
	c = 0;
	if (chaine == 0)
		return (chaine);
	while (s[c] != '\0')
	{
		chaine[c] = f(c, s[c]);
		c++;
	}
	chaine[c] = '\0';
	return (chaine);
}
