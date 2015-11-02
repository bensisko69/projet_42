/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 13:14:30 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

std::string	Victim::getName(void) const
{
	return this->_name;
}

void		Victim::setName(std::string name)
{
	this->_name = name;
}

Victim::Victim(std::string name): _name(name)
{
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
	return;
}

Victim::Victim(Victim const &src)
{
	*this = src;
	std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim(void)
{
	std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
	return;
}

Victim &Victim::operator=(Victim const &rhs)
{
	this->_name = rhs._name;
	return *this;
}

std::ostream & operator<<(std::ostream &o, Victim const &rhs)
{
	o << "I am " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

void	Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}