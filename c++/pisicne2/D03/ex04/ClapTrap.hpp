/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 18:11:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 21:36:58 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

typedef unsigned int uint;

class ClapTrap{

	public:
		~ClapTrap(void);
		ClapTrap&		operator=(ClapTrap const &rhs);
		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		unsigned int	getHitPoint(void) const;
		unsigned int	getMaxHitPoint(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getMaxEnergyPoints(void) const;
		unsigned int	getLevel(void) const;
		unsigned int	getMeleeAttack(void) const;
		unsigned int	getRangedAttack(void) const;
		unsigned int	getArmorDamage(void) const;
		std::string		getName(void) const;


	protected:
		ClapTrap(void);
		ClapTrap(ClapTrap const &);
		ClapTrap(uint, uint, uint, uint, uint, uint, uint, uint, std::string);
		unsigned int _hitPoints, _maxHitPoints, _energyPoints, _maxEnergyPoints, _level;
		unsigned int _meleeAttackDamage, _rangedAttackDamage, _armorDamageReduction;
		std::string  _name;
};

#endif