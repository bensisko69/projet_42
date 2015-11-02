/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:17:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 17:56:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>

class ScavTrap{

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const& src);
		ScavTrap	&operator=(ScavTrap const &rhs);
		
		void			challengeNewcomer(std::string const & target);
		typedef void(ScavTrap::*func)(std::string const &);
		static const func tab[];
		void			crystal(std::string const & target);
		void			glass(std::string const & target);
		void			ruby(std::string const & target);
		void			diamond(std::string const & target);
		void			emerald(std::string const & target);

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


	private:
		unsigned int _hitPoints, _maxHitPoints, _energyPoints, _maxEnergyPoints, _level;
		unsigned int _meleeAttackDamage, _rangedAttackDamage, _armorDamageReduction;
		std::string  _name;
		ScavTrap(void);
};

#endif