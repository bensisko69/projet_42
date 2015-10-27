/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:11:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:35:44 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_isalnum(void)
{
	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_isalnum: \n", 20);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isalnum('B'));
	write(1, "\n", 1);
	write(1, "tests char = '&' \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isalnum('&'));
	write(1, "\n", 1);
	write(1, "\033[38;5;1m", 9);
	write(1, "tests isalnum: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "tests char = B \n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(isalnum('B'));
	write(1, "\n", 1);
	write(1, "tests char = '&' \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(isalnum('&'));
	write(1, "\n\n", 2);
}
