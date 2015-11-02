/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 18:44:49 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): _hitPoints(100), _maxHitPoints(100), _energyPoints(100), _maxEnergyPoints(100), _level(1), _meleeAttackDamage(30), _rangedAttackDamage(20), _armorDamageReduction(5), _name(name)
{
	std::cout << "FR4G-TP " << _name << " weapons of bastards for real bastards." << std::endl;
	return;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Hyperion offers exceptional discounts on your next resurrection ending in 5 , 4, 3 , 2, 1 , 0 ... Too bad !" << std::endl;
	return;
}

FragTrap::FragTrap(FragTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap&		FragTrap::operator=(FragTrap const &rhs)
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

void		FragTrap::rangedAttack(std::string const & target)
{ 
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage !" << std::endl;
}

void		FragTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " directly attacks " << target << ", causing " << _meleeAttackDamage << " points of damage !" << std::endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " takes " << amount << " points of damage !" << std::endl;
	if ((amount > _hitPoints) && _hitPoints > 0)
	{
		_hitPoints = 0;
		std::cout << "FR4G-TP " << _name << " you lose " << _hitPoints <<  " of life " << std::endl;
	}
	else if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "FR4G-TP " << _name << " " << _hitPoints << " points of life !" << std::endl;
	}
}

void		FragTrap::beRepaired(unsigned int amount)
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

unsigned int			FragTrap::getHitPoint(void) const
{
	return this->_hitPoints;
}

unsigned int			FragTrap::getMaxHitPoint(void) const
{
	return this->_maxHitPoints;
}

unsigned int			FragTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int			FragTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

unsigned int			FragTrap::getLevel(void) const
{
	return this->_level;
}

unsigned int			FragTrap::getMeleeAttack(void) const
{
	return this->_meleeAttackDamage;
}

unsigned int			FragTrap::getRangedAttack(void) const
{
	return this->_rangedAttackDamage;
}

unsigned int			FragTrap::getArmorDamage(void) const
{
	return this->_armorDamageReduction;
}

std::string	FragTrap::getName(void) const
{
	return this->_name;
}
