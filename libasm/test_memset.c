/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 13:49:26 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:37:00 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_memset(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 9);
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests ft_memset: \n");
	WRITE(1, "\033[0m");
	write(1, ft_memset(str, 54, 9), 9);
	WRITE(1, "\n");
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests memset: \n");
	WRITE(1, "\033[0m");
	write(1, memset(str, 42, 4), 9);
	WRITE(1, "\n\n");
}
