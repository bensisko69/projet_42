/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:11:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:36:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_isascii(void)
{
	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_isascii: \n", 20);
	write(1, "\033[0m", 4);
	write(1, "tests char = '+'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isascii('+'));
	write(1, "\n", 1);
	write(1, "tests int = 197 \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isascii(197));
	write(1, "\n", 1);
	write(1, "\033[38;5;1m", 9);
	write(1, "tests isascii: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "tests char = '+'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(isascii('+'));
	write(1, "\n", 1);
	write(1, "tests int = 197 \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(isascii(197));
	write(1, "\n\n", 2);
}
