/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 17:39:26 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:36:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_memcpy(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 9);
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests ft_memcpy: \n");
	WRITE(1, "\033[0m");
	write(1, ft_memcpy(str, "999999999", 9), 9);
	WRITE(1, "\n");
	write(1, ft_memcpy(str, "54", 2), 9);
	WRITE(1, "\n");
	ft_bzero(str, 9);
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests memcpy: \n");
	WRITE(1, "\033[0m");
	write(1, memcpy(str, "999999999", 9), 9);
	WRITE(1, "\n");
	write(1, memcpy(str, "54", 2), 9);
	WRITE(1, "\n\n");
}
