/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:17:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:30:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
	_name = name;
	_energyPoints = 50;
	_maxEnergyPoints = 50;
	_level = 1;
	_meleeAttackDamage = 20;
	_rangedAttackDamage = 15;
	_armorDamageReduction = 3;
	std::cout << "SC4G-TP " << _name << " I will give your skin to feed my parrot !" << std::endl;
	return;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "SC4G-TP Final death . Death ... infinite infinitive ." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

const ScavTrap::func ScavTrap::tab[] = {
	&ScavTrap::crystal,
	&ScavTrap::glass,
	&ScavTrap::ruby,
	&ScavTrap::diamond,
	&ScavTrap::emerald,
};

void		ScavTrap::challengeNewcomer(std::string const & target)
{
	(this->*(tab[rand() % 5]))(target);
}

void		ScavTrap::crystal(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with rain crystal !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		ScavTrap::glass(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with rain glass !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		ScavTrap::ruby(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with rain ruby !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		ScavTrap::diamond(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with rain diamond !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}

void		ScavTrap::emerald(std::string const & target)
{
	if (_energyPoints > 25 && _hitPoints > 0)
	{
		_energyPoints -= 25;
		std::cout << "FR4G-TP " << _name << " attacks " << target << " with rain emerald !" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _energyPoints << " energy points !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP not enough energy points" <<std::endl;
}
