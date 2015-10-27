/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/30 12:36:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 17:15:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_putnbr(int n)
{
	char	nbr;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		nbr = '0' + n;
		write(1, &nbr, 1);
	}
}

int		main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	test_bzero();
	test_puts();
	test_strcat();
	test_memset();
	test_memcpy();
	test_strdup();
	test_strlen();
	test_cat();
	return (0);
}
