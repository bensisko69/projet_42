/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:21:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 22:14:10 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human(void){}

Human::~Human(void){}

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "meleeAttack called on target " << target<< std::endl; 
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "rangedAttack called on target " << target<< std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidatingShout called aon target " << target<< std::endl;
}

const std::string Human::array_name[] = {
	"meleeAttack",
	"rangedAttack",
	"intimidatingShout"
};

const Human::func Human::tab[] = {
	&Human::meleeAttack,
	&Human::rangedAttack,
	&Human::intimidatingShout,
	&Human::error
};

void	Human::action(std::string const & action_name, std::string const & target)
{
	int i = 0;

	while (i < 3 && array_name[i] != action_name)
		i++;
	(this->*(tab[i]))(target);
}

void Human::error(std::string const & target)
{
	std::cout << "No valid entry" << std::endl;
}
