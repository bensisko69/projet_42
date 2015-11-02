/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:24:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 14:27:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void): _type("canibal")
{
	std::cout << "Constructor ZombieEvent "<< _type <<" called (Whith a default type)" << std::endl << std::endl;
	return;
}

ZombieEvent::~ZombieEvent(void)
{
	std::cout << "Destructor ZombieEvent " << _type << " called" << std::endl;
	return;
}

void	ZombieEvent::setZombieType(std::string type)
{
	_type = type;
}

Zombie	*ZombieEvent::newZombie(std::string name)
{
	Zombie	*Zombies = new Zombie(name, _type);
	return (Zombies);
}

void	ZombieEvent::randomChump(void)
{
	std::string array[5] = {"Magalie", "Paul", "Mickael", "Audrey", "Pierre"};
	Zombie	*Zombies = new Zombie(array[rand() % 5], _type);
	Zombies->announce();
	delete Zombies;

}