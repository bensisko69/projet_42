/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 22:22:35 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 14:26:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

void		RadScorpion::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

RadScorpion::RadScorpion(void) : Enemy(80 ,"RadScorpion")
{
	std::cout << "* click click click *" <<std::endl;
	return;
}

RadScorpion::~RadScorpion(void)
{
	std::cout << "* SPROTCH *" <<std::endl;
	return;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src)
{

}

RadScorpion & RadScorpion::operator=(RadScorpion const &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}