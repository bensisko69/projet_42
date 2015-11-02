/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 15:34:40 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "SuperMutant.hpp"

Enemy::Enemy(int hp, std::string const & type): _hp(hp), _type(type)
{
	return;
}

Enemy::~Enemy(void)
{
	return;
}

Enemy::Enemy(Enemy const &src): _hp(src._hp), _type(src._type)
{

}

std::string const	&Enemy::getType(void) const
{
	return this->_type;
}

int					Enemy::getHP() const
{
	return this->_hp;
}

void		Enemy::takeDamage(int nb)
{
	if (nb > 0 && _hp > 0)
	{
		if (nb >= _hp )
			_hp = 0;
		else
			_hp -= nb;
	}
}

Enemy & Enemy::operator=(Enemy const &rhs)
{
	this->_hp = rhs._hp;
	return *this;
}
