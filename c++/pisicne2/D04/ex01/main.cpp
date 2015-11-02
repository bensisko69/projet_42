/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 16:23:12 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"

int	main (void)
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->attack(b);
	zaz->equip(pr);
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->recoverAP();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	std::cout << b->getType() << " " << b->getHP() << "PV" << std::endl;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	zaz->attack(b);
	std::cout << c->getType() << " " << c->getHP() << "PV" << std::endl;
	zaz->attack(c);
	std::cout << c->getType() << " " << c->getHP() << "PV" << std::endl;
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << c->getType() << " " << c->getHP() << "PV" << std::endl;
	std::cout << *zaz;
	zaz->attack(c);
	std::cout << *zaz;
	std::cout << c->getType() << " " << c->getHP() << "PV" << std::endl;
	zaz->attack(c);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	return 0;
}