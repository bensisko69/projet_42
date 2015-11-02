/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 15:47:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _apcost(apcost), _damage(damage)
{
	return;
}

AWeapon::AWeapon(AWeapon const &src): _name(src._name)
{

}

AWeapon &AWeapon::operator=(AWeapon const &rhs)
{
	this->_apcost = rhs._apcost;
	this->_damage = rhs._damage;
	return *this;
}

AWeapon::~AWeapon(void)
{
	return;
}

std::string const	&AWeapon::getName(void) const
{
	return this->_name;
}

int					AWeapon::getAPCost(void) const
{
	return this->_apcost;
}

int					AWeapon::getDamage(void) const
{
	return this->_damage;
}
