/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 15:19:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170 ,"Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" <<std::endl;
	return;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." <<std::endl;
	return;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src)
{

}

void		SuperMutant::takeDamage(int nb)
{
	if (nb <= 3)
		nb = 0;
	else
		nb -= 3;
	Enemy::takeDamage(nb);
}

SuperMutant & SuperMutant::operator=(SuperMutant const &rhs)
{
	Enemy::operator=(rhs);
	return *this;
}