/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:56:19 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:33:04 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"

NinjaTrap::NinjaTrap(std::string name): 
	ClapTrap(60, 60, 120, 120 , 1, 60, 5, 0, name)
{
	std::cout << "NJ4G-TP " << _name <<" At Last! The world to collide ! " << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NJ4G-TP I'll use your head as a hood !" << std::endl;
	return;
}

NinjaTrap&		NinjaTrap::operator=(NinjaTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

void	NinjaTrap::ninjaShoebox(FragTrap &src)
{
	std::cout << src.getName() << " FragTrap is born" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &src)
{
	std::cout << src.getName() << " NinjaTrap is born" << std::endl;
}


void	NinjaTrap::ninjaShoebox(ScavTrap &src)
{
	std::cout << src.getName() << " ScavTrap is born" << std::endl;
}

