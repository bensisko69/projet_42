/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 13:40:29 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"
#include "Sorcerer.hpp"
#include "Victim.hpp"

int main()
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jim");
	Victim		*vbob = new Peon("Bob");
	Peon		joe("Joe");

	Sorcerer	robert2(robert);
	Sorcerer	robert3("Another Robert", "el Magnifico");
	Victim		jim2(jim);
	Victim		jim3("Another Jim");
	Peon		joe2(joe);
	Peon		joe3("Another Joe");

	robert3 = robert;
	jim3 = jim;
	joe3 = joe;

	std::cout << robert << jim << joe << *vbob;

	robert.polymorph(jim);
	robert.polymorph(joe);
	robert.polymorph(*vbob);
	delete vbob;
	return 0;
}