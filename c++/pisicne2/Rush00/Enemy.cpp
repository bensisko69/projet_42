/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 23:10:46 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy		&Enemy::operator=(Enemy const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Enemy::Enemy(WINDOW const * win, int x, int y): AEntities(win, x, y, '#', CYAN)
{
}

Enemy::~Enemy(void)
{
}

Enemy::Enemy(Enemy const &src): AEntities(src)
{
}

void				Enemy::shoot(void)
{
	_missile = new Missiles(_win, _x - 3, _y, -1);
}

void				Enemy::movement(void)
{
	_x -= 1;
}

void				Enemy::update(void)
{
	_missile = 0;

	if (AEntities::loopCount % 2)
		movement();
	else if (rand() % 500 < 5)
		shoot();
}
