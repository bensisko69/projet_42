/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 13:14:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

std::string	Sorcerer::getName(void) const
{
	return this->_name;
}

std::string	Sorcerer::getTitle(void) const
{
	return this->_title;
}

Sorcerer::Sorcerer(std::string name, std::string title): _name(name), _title(title)
{
	std::cout << _name << " , " << _title << " , is born !" << std::endl;
	return;
}

Sorcerer::Sorcerer(Sorcerer const &src)
{
	*this = src;
	std::cout << _name << " , " << _title << " , is born !" << std::endl;
}

Sorcerer::~Sorcerer(void)
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
	return;
}

Sorcerer &Sorcerer::operator=(Sorcerer const &rhs)
{
	this->_name = rhs._name;
	this->_title = rhs._title;
	return *this;
}

std::ostream & operator<<(std::ostream &o, Sorcerer const &rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return o;
}

void Sorcerer::polymorph(Victim const &o) const
{
	o.getPolymorphed();
}