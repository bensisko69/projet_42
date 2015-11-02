/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 22:33:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:35:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"


SuperTrap::SuperTrap(std::string name):
ClapTrap(100, 100, 120, 120 , 1, 60, 20, 5, name)
{
	std::cout << "SP4G-TP " << _name << " Fuck! You've Really Bought this shit! " << std::endl;
	return;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "DSSP-TP BOOM shaka laka !!" << std::endl;
	return;
}

SuperTrap::SuperTrap(SuperTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

SuperTrap&		SuperTrap::operator=(SuperTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

