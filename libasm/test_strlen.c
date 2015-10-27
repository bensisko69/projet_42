/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:27 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 17:55:52 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_strlen(void)
{
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests ft_strlen: \n");
	WRITE(1, "\033[0m");
	WRITE(1, "cette chaine a 23 char\n");
	ft_putnbr(ft_strlen("cette chaine a 22 char\n"));
	WRITE(1, "\n");
	WRITE(1, "et elle a 18 char\n");
	ft_putnbr(ft_strlen("et elle a 18 char\n"));
	WRITE(1, "\n");
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests strlen: \n");
	WRITE(1, "\033[0m");
	WRITE(1, "cette chaine a 23 char\n");
	ft_putnbr(strlen("cette chaine a 22 char\n"));
	WRITE(1, "\n");
	WRITE(1, "et elle a 18 char\n");
	ft_putnbr(strlen("et elle a 18 char\n"));
	WRITE(1, "\n\n");
}
