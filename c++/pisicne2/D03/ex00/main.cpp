/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 18:45:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(int, char**)
{
	srand(time(0));
	FragTrap lol = FragTrap("lol");
	lol.rangedAttack("Paul");
	lol.meleeAttack("Paul");
	lol.takeDamage(25);
	lol.beRepaired(5);
	lol.vaulthunter_dot_exe("Paul");
	lol.takeDamage(65);
	lol.beRepaired(3);
	lol.vaulthunter_dot_exe("Paul");
	lol.takeDamage(5);
	lol.beRepaired(3);
	lol.vaulthunter_dot_exe("Paul");
	lol.takeDamage(2);
	lol.takeDamage(5);
	lol.vaulthunter_dot_exe("Paul");
	lol.beRepaired(3);
	lol.takeDamage(25);
	return 0;
}