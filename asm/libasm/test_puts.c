/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 20:20:50 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/14 16:37:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_puts(void)
{
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests ft_puts: \n");
	WRITE(1, "\033[0m");
	WRITE(1, "str = 123456789\n");
	ft_puts("123456789");
	WRITE(1, "str = null\n");
	ft_puts(0);
	WRITE(1, "\033[38;5;1m");
	WRITE(1, "tests puts: \n");
	WRITE(1, "\033[0m");
	WRITE(1, "str = 123456789\n");
	puts("123456789");
	WRITE(1, "str = null\n");
	puts(0);
	WRITE(1, "\n");
}
