/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:33:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FR4G-TP " << _name << " weapons of bastards for real bastards." << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(100, 100, 100, 100 , 1, 30, 20, 5, name)
{
	std::cout << "FR4G-TP " << _name << " weapons of bastards for real bastards." << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "DSFR-TP Hyperion offers exceptional discounts on your next resurrection ending in 5 , 4, 3 , 2, 1 , 0 ... Too bad !" << std::endl;
	return;
}

FragTrap&		FragTrap::operator=(FragTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

const FragTrap::func FragTrap::tab[] = {
	&FragTrap::water,
	&FragTrap::fire,
	&FragTrap::wind,
	&FragTrap::stone,
	&FragTrap::ice,
};

void		FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	(this->*(tab[rand() % 5]))(target);
}

void		FragTrap::fire(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with flamethrower !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		FragTrap::wind(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with tornado !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		FragTrap::stone(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with avalanche !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		FragTrap::ice(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with ice laser !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		FragTrap::water(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with water gun !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}
