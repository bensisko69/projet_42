/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:11:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:36:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_isprint(void)
{
	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_isprint: \n", 20);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isprint('B'));
	write(1, "\n", 1);
	write(1, "tests code ascii = soh\n", 23);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isprint(1));
	write(1, "\n", 1);
	write(1, "\033[38;5;1m", 9);
	write(1, "tests isprint: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "tests char = B \n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(isprint('B'));
	write(1, "\n", 1);
	write(1, "tests code ascii = soh\n", 23);
	write(1, "ret = ", 6);
	ft_putnbr(isprint(1));
	write(1, "\n\n", 2);
}
