/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 14:43:42 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 15:55:05 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int nbr): _nbr(nbr)
{
	std::cout << "Constructor ZombieHorde called" << std::endl;
	std::cout << std::endl;
	if (nbr == 0)
		std::cout << "Nbr > 0 please" << std::endl;
	else if(nbr > 0)
	{
		_horde = new Zombie[nbr];
		for (int i = 0; i < _nbr; i++)
			_horde[i].announce();
	}
	return;
}

ZombieHorde::~ZombieHorde(void)
{
	delete [] _horde;
	std::cout << std::endl;
	std::cout << "Destructor ZombieHorde called" << std::endl;
	return;
}