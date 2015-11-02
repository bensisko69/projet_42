/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 12:03:59 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/06 22:16:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "Awesome.class.hpp"

int	main (void)
{
	int	i = 0;
	int j = 0;
	int ID = 0;
	Awesome instace[8];

	if (!isatty(STDIN_FILENO)) {
		std::cerr << "input not a tty" << std::endl;
		return 1;
	}

	std::string CMD;
	for(;;)
	{
		std::cout << "Please enter the command : ";
		if (std::getline(std::cin, CMD) == 0)
			break;
		if (CMD == "EXIT")
			return (1);
		else if (CMD == "ADD")
		{
			if (i == 8)
				std::cout << "Max 8 Contact" << std::endl;
			else
				instace[i++].add();
		}
		else if (CMD == "SEARCH")
		{
			j = 0;
			while (j < i)
			{
				instace[j].aff(j);
				j++;
			}
			std::cout << "Please choose index : ";
			std::cin >> ID;
			if (std::cin.good())
			{
				if (ID >= i || ID < 0)
					std::cout << "Index is not valid" << std::endl;
				else
					instace[ID].aff_id(ID);
			}
			else
				std::cout << "Number please." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	return (0);
}