/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 20:19:44 by wburgos           #+#    #+#             */
/*   Updated: 2015/04/12 23:10:36 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.hpp"

Asteroids		&Asteroids::operator=(Asteroids const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

Asteroids::Asteroids(WINDOW const * win, int x, int y): AEntities(win, x, y, 'O', YELLOW)
{
}

Asteroids::~Asteroids(void)
{
}

Asteroids::Asteroids(Asteroids const &src): AEntities(src)
{
}

void				Asteroids::movement(void)
{
	_x -= 1;
}

void				Asteroids::update(void)
{
	if (AEntities::loopCount % 2)
		movement();
}
