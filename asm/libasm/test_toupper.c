/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:11:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:40:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	test2(char nbr)
{
	write(1, "\033[38;5;1m", 9);
	write(1, "tests toupper: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'b'\n", 17);
	write(1, "ret = ", 6);
	nbr = toupper('b');
	write(1, &nbr, 1);
	write(1, "\n", 1);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	nbr = toupper('B');
	write(1, &nbr, 1);
	write(1, "\n\n", 2);
}

void		test_toupper(void)
{
	char nbr;

	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_toupper: \n", 20);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'b'\n", 17);
	write(1, "ret = ", 6);
	nbr = ft_toupper('b');
	write(1, &nbr, 1);
	write(1, "\n", 1);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	nbr = ft_toupper('B');
	write(1, &nbr, 1);
	write(1, "\n", 1);
	test2(nbr);
}
