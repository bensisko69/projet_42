/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:45:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog " << std::endl;
	return;
}

Peon::Peon(Peon const &src): Victim(src)
{
	*this = src;
	std::cout << "Zog zog " << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..."<< std::endl;
	return;
}

Peon &Peon::operator=(Peon const &rhs)
{
	Victim::operator=(rhs);
	return *this;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
}