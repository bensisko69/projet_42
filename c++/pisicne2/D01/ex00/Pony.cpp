/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 11:35:02 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 12:14:15 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name, std::string allocate) : _name(name), _allocate(allocate)
{
	std::cout << "My name is " << _name << " and I'm allocated " << _allocate << std::endl;
	return;
}

Pony::~Pony(void)
{
	std::cout << _name << " is dead" << std::endl;
	return;
}
