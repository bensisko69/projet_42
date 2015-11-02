/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 22:02:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "NinjaTrap.hpp"

int	main(int, char**)
{
	srand(time(0));
	ScavTrap paul = ScavTrap("Paul");
	FragTrap luc = FragTrap("Luc");
	NinjaTrap pierre = NinjaTrap("Pierre");
	pierre.ninjaShoebox(paul);
	pierre.ninjaShoebox(luc);
	pierre.ninjaShoebox(pierre);
	return 0;
}