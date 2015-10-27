/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/16 16:18:16 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 18:03:13 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>

static void	print(char *str)
{
	write(1, "\033[38;5;1m", 9);
	write(1, str, 15);
	write(1, "\033[0m", 4);
}

void		test_cat(void)
{
	int	fd;

	fd = open("/dev/random", O_RDONLY);
	print("tests ft_cat: \n");
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(0);
	ft_cat(open("Makefile", O_RDONLY));
	close(fd);
}
