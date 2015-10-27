/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 18:11:43 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 18:02:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	*ft_memalloc(size_t size)
{
	void	*c;

	c = malloc(sizeof(char*) * size);
	if (c == 0)
		return (0);
	ft_bzero(c, size);
	return (c);
}

void		test_strdup(void)
{
	char	*dup;
	char	*lol;

	dup = ft_memalloc(10);
	strcpy(dup, "999999999");
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests ft_strdup: \n");
	WRITE(1, "\033[0m");
	lol = ft_strdup(dup);
	write(1, lol, 9);
	free(lol);
	WRITE(1, "\n");
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests strdup: \n");
	WRITE(1, "\033[0m");
	lol = strdup(dup);
	write(1, lol, 9);
	free(lol);
	WRITE(1, "\n\n");
}
