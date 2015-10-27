/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:13:20 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:37:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_strcat(void)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 12);
	strcpy(str, "lossssl");
	if (str)
	{
		WRITE(1, "\033[38;5;1m");
		WRITE(1, "tests ft_strcat: \n");
		WRITE(1, "\033[0m");
		write(1, ft_strcat(str, "lol1"), 11);
		WRITE(1, "\n");
		WRITE(1, "\033[38;5;1m");
		WRITE(1, "test strcat: \n");
		WRITE(1, "\033[0m");
		write(1, strcat(str, "lol1"), 11);
		WRITE(1, "\n\n");
	}
}
