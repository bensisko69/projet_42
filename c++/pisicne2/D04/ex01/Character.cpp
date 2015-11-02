/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 22:22:35 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 16:16:18 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name): _name(name), _ap(40), _Aweapon(NULL)
{
	return;
}

Character &Character::operator=(Character const &rhs)
{
	this->_name = rhs._name;
	this->_ap = rhs._ap;
	this->_Aweapon = rhs._Aweapon;
	return *this;
}

Character::~Character(void)
{
	return;
}

Character::Character(Character const &src)
{
	*this = src;
}

void Character::recoverAP(void)
{
	if (this->_ap > 30)
		this->_ap = 40;
	else
		this->_ap += 10;
}

void Character::equip(AWeapon* src)
{
	_Aweapon = src;
}

void Character::attack(Enemy* src)
{
	if (_Aweapon != NULL && src->getHP() > 0)
	{
		if (_ap > _Aweapon->getAPCost())
		{
			std::cout << this->_name << " attacks " << src->getType() << " with a " << _Aweapon->getName() << std::endl;
			_ap -= _Aweapon->getAPCost();
			_Aweapon->attack();
			src->takeDamage(_Aweapon->getDamage());
			if (src->getHP() == 0)
				delete src;
		}
	}
}

std::string	const	&Character::getName(void) const
{
	return this->_name;
}

int		Character::getAp(void) const
{
	return this->_ap;
}

AWeapon*		Character::getAweapon(void) const
{
	return this->_Aweapon;
}

std::ostream & operator<<(std::ostream &o, Character const &rhs)
{
	if (rhs.getAweapon())
	{
		o << rhs.getName() << " has " << rhs.getAp() << " AP and wields a " << rhs.getAweapon()->getName() << std::endl;
	}
	else
		o << rhs.getName() << " has " << rhs.getAp() << " AP and is unarmed" << std::endl;
	return o;
}
