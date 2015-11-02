/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 12:24:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 14:11:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


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