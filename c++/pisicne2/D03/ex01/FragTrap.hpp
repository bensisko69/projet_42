/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 17:24:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>

class FragTrap{

	public:
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const& src);
		FragTrap	&operator=(FragTrap const &rhs);
		
		void		vaulthunter_dot_exe(std::string const & target);
		typedef void(FragTrap::*func)(std::string const &);
		static const func tab[];
		void			fire(std::string const & target);
		void			wind(std::string const & target);
		void			stone(std::string const & target);
		void			ice(std::string const & target);
		void			water(std::string const & target);

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
		FragTrap(void);
};

#endif