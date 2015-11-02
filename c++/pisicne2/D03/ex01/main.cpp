/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 17:49:29 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(int, char**)
{
	srand(time(0));
	ScavTrap paul = ScavTrap("Paul");
	FragTrap luc = FragTrap("Luc");
	paul.rangedAttack("luc");
	luc.rangedAttack("paul");
	paul.meleeAttack("luc");
	luc.meleeAttack("paul");
	paul.takeDamage(25);
	luc.takeDamage(20);
	paul.beRepaired(5);
	luc.beRepaired(5);
	paul.challengeNewcomer("luc");
	luc.vaulthunter_dot_exe("paul");
	paul.takeDamage(65);
	luc.takeDamage(25);
	paul.beRepaired(3);
	luc.beRepaired(5);
	paul.challengeNewcomer("luc");
	luc.vaulthunter_dot_exe("paul");
	paul.takeDamage(5);
	luc.takeDamage(25);
	paul.beRepaired(3);
	luc.beRepaired(5);
	paul.challengeNewcomer("luc");
	luc.vaulthunter_dot_exe("paul");
	paul.takeDamage(2);
	luc.takeDamage(25);
	paul.takeDamage(5);
	luc.takeDamage(25);
	paul.challengeNewcomer("luc");
	luc.vaulthunter_dot_exe("paul");
	paul.beRepaired(3);
	luc.beRepaired(5);
	paul.takeDamage(605);
	luc.takeDamage(605);
	paul.beRepaired(3);
	luc.beRepaired(5);
	paul.challengeNewcomer("luc");
	luc.vaulthunter_dot_exe("paul");
	return 0;
}