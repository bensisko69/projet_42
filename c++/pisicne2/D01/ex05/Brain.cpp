/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:14:38 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 18:18:22 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	return;
}

Brain::~Brain(void)
{
	return;
}

std::string	Brain::identify(void) const
{
	std::stringstream ss;

	ss << this;
	return (ss.str());
}