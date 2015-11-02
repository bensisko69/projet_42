/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:24:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 15:48:23 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie(void)
{
	std::string array[10] = {"Magalie", "Paul", "Mickael", "Audrey", "Pierre", "Luc", "Papa", "Maman", "Marion", "Lucie"};
	std::string array2[4] = {"Hobbit", "Urgal", "Elfe", "Nain"};
	_name = array[rand() % 10];
	_type = array2[rand() % 4];
	std::cout << "Constructor " << _name << " is called" << std::endl;
	return;
}

Zombie::Zombie(std::string name, std::string type): _name(name), _type(type)
{

	std::cout << "Constructor Zombie's " << _name << " called" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor Zombie's " << _name << " called" << std::endl;
	return;
}

void	Zombie::announce(void)
{
		std::cout << "My name is " << _name << " and i am type " << _type << std::endl;
}