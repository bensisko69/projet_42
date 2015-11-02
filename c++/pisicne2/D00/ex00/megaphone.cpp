/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 10:39:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/06 22:31:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		for (int a = 0; av[i][a] != '\0'; a++)
		{
			if (av[i][a] >= 'a' && av[i][a] <= 'z')
				av[i][a] -= 32;
			std::cout << av[i][a];
		}
	}
	std::cout << std::endl;
	return (0);
}