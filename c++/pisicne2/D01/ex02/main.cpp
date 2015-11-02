/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:24:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 14:28:13 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int	main(int, char**)
{
	srand(time(0));
	ZombieEvent ze;
	ze.setZombieType("Pony");
	std::cout << "Generate random zombie" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		ze.randomChump();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Generate zombie" << std::endl;
	Zombie *NewZombie = ze.newZombie("Loic");
	NewZombie->announce();
	delete NewZombie;
	std::cout << std::endl;
	return (0);
}