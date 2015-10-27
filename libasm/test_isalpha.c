/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:11:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:35:56 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_isalpha(void)
{
	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_isalpha: \n", 20);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isalpha('B'));
	write(1, "\n", 1);
	write(1, "tests int = '&' \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(ft_isalpha('&'));
	write(1, "\n", 1);
	write(1, "\033[38;5;1m", 9);
	write(1, "tests isalpha: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "tests char = 'B'\n", 17);
	write(1, "ret = ", 6);
	ft_putnbr(isalpha('B'));
	write(1, "\n", 1);
	write(1, "tests int = '&' \n", 18);
	write(1, "ret = ", 6);
	ft_putnbr(isalpha('&'));
	write(1, "\n\n", 2);
}
