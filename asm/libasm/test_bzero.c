/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 15:13:51 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/10/26 18:00:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	test_bzero(void)
{
	char	str[9];
	char	str2[9];

	strcpy(str, "bonjour");
	strcpy(str2, "bonjour");
	write(1, "\033[38;5;1m", 9);
	write(1, "tests ft_bzero: \n", 17);
	write(1, "\033[0m", 4);
	write(1, "chaine 1 = ", 11);
	write(1, str, 8);
	write(1, "\n", 1);
	write(1, "chaine 1 avec ft_bzero = ", 25);
	ft_bzero(str, 3);
	write(1, str, 8);
	write(1, "\n", 1);
	write(1, "\033[38;5;1m", 9);
	write(1, "tests bzero: \n", 14);
	write(1, "\033[0m", 4);
	write(1, "chaine 2 = ", 11);
	write(1, str2, 8);
	write(1, "\n", 1);
	write(1, "chaine 2 avec bzero = ", 22);
	bzero(str2, 3);
	write(1, str2, 8);
	write(1, "\n\n", 2);
}
