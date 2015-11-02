/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:17:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 23:11:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): _hitPoints(100), _maxHitPoints(100), _energyPoints(50), 
_maxEnergyPoints(50), _level(1), _meleeAttackDamage(20), _rangedAttackDamage(15), 
_armorDamageReduction(3), _name(name)
{
	std::cout << "SC4G-TP " << _name << " I will give your skin to feed my parrot !" << std::endl;
	return;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Final death . Death ... infinite infinitive ." << std::endl;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap&		ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_hitPoints = rhs.getHitPoint();
		this->_maxHitPoints = rhs.getMaxHitPoint();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_maxEnergyPoints = rhs.getMaxEnergyPoints();
		this->_level = rhs.getLevel();
		this->_meleeAttackDamage = rhs.getMeleeAttack();
		this->_rangedAttackDamage = rhs.getRangedAttack();
		this->_armorDamageReduction = rhs.getArmorDamage();
		this->_name = rhs.getName();
	}
	return *this;
}

void		ScavTrap::rangedAttack(std::string const & target)
{ 
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage !" << std::endl;
}

void		ScavTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " directly attacks " << target << ", causing " << _meleeAttackDamage << " points of damage !" << std::endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " takes " << amount << " points of damage !" << std::endl;
	if (_armorDamageReduction > amount)
		amount = 0;
	else
		amount = amount - _armorDamageReduction;
	if ((amount > _hitPoints) && _hitPoints > 0)
	{
		_hitPoints = 0;
		std::cout << "FR4G-TP " << _name << " you lose " << _hitPoints <<  " of life " << std::endl;
	}
	else if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "FR4G-TP " << _name << " regains " << _armorDamageReduction << " points of armor" << std::endl;
		std::cout << "FR4G-TP " << _name << " " << _hitPoints << " points of life !" << std::endl;
	}
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	if ((_hitPoints < _maxHitPoints) && _hitPoints > 0)
	{
		if ((_hitPoints += amount) >= _maxHitPoints)
			_hitPoints = _maxHitPoints;
		std::cout << "FR4G-TP " << _name << " regains " << amount << " points of life !" << std::endl;
	}
	else if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " " << _hitPoints << " points of life !" << std::endl;
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

unsigned int			ScavTrap::getHitPoint(void) const
{
	return this->_hitPoints;
}

unsigned int			ScavTrap::getMaxHitPoint(void) const
{
	return this->_maxHitPoints;
}

unsigned int			ScavTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int			ScavTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

unsigned int			ScavTrap::getLevel(void) const
{
	return this->_level;
}

unsigned int			ScavTrap::getMeleeAttack(void) const
{
	return this->_meleeAttackDamage;
}

unsigned int			ScavTrap::getRangedAttack(void) const
{
	return this->_rangedAttackDamage;
}

unsigned int			ScavTrap::getArmorDamage(void) const
{
	return this->_armorDamageReduction;
}

std::string	ScavTrap::getName(void) const
{
	return this->_name;
}