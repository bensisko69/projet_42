/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 22:22:35 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 15:50:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
	public:
		Character(std::string const & name);
		~Character();
		Character(Character const &src);
		Character &operator=(Character const &rhs);
		void recoverAP();
		void equip(AWeapon*);
		void attack(Enemy*);
		std::string const	&getName() const;
		int					getAp() const;
		AWeapon*			getAweapon(void) const;

	private:
		Character(void);
		std::string _name;
		int			_ap;
		AWeapon		*_Aweapon;
};

std::ostream & operator<<(std::ostream &o, Character const &rhs);

#endif