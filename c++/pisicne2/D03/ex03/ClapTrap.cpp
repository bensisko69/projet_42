/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 18:11:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 21:34:26 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Constructor ClapTrap called" << std::endl;

	return;
}

ClapTrap::ClapTrap(uint hitPoint, uint maxHit, uint energyP, uint maxEnergy ,uint level, uint melee, uint ranged, uint armor, std::string name) : 
	_hitPoints(hitPoint), 
	_maxHitPoints(maxHit),
	_energyPoints(energyP),
	_maxEnergyPoints(maxEnergy),
	_level(level),
	_meleeAttackDamage(melee),
	_rangedAttackDamage(ranged),
	_armorDamageReduction(armor),
	_name(name)
{

}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor ClapTrap called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap&		ClapTrap::operator=(ClapTrap const &rhs)
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

void		ClapTrap::takeDamage(unsigned int amount)
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

void		ClapTrap::beRepaired(unsigned int amount)
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

void		ClapTrap::rangedAttack(std::string const & target)
{ 
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " attacks " << target << " at range, causing " << _rangedAttackDamage << " points of damage !" << std::endl;
}

void		ClapTrap::meleeAttack(std::string const & target)
{
	if (_hitPoints > 0)
		std::cout << "FR4G-TP " << _name << " directly attacks " << target << ", causing " << _meleeAttackDamage << " points of damage !" << std::endl;
}

unsigned int			ClapTrap::getHitPoint(void) const
{
	return this->_hitPoints;
}

unsigned int			ClapTrap::getMaxHitPoint(void) const
{
	return this->_maxHitPoints;
}

unsigned int			ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int			ClapTrap::getMaxEnergyPoints(void) const
{
	return this->_maxEnergyPoints;
}

unsigned int			ClapTrap::getLevel(void) const
{
	return this->_level;
}

unsigned int			ClapTrap::getMeleeAttack(void) const
{
	return this->_meleeAttackDamage;
}

unsigned int			ClapTrap::getRangedAttack(void) const
{
	return this->_rangedAttackDamage;
}

unsigned int			ClapTrap::getArmorDamage(void) const
{
	return this->_armorDamageReduction;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}