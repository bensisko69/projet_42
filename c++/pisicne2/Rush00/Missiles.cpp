/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:08:14 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 23:16:20 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles::Missiles(WINDOW const * win, int x, int y, int direction):
AEntities(win, x, y, '-', WHITE), _direction(direction)
{
}

Missiles::~Missiles(void)
{
}

Missiles::Missiles(Missiles const &src): AEntities(src)
{

}

Missiles &			Missiles::operator=(Missiles const &rhs)
{
	AEntities::operator=(rhs);
	return *this;
}

void				Missiles::movement(void)
{
	_x += _direction;
}

void				Missiles::update(void)
{
	movement();
}
