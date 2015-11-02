/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 17:17:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:30:34 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{

	public:
		ScavTrap(std::string name);
		~ScavTrap(void);
		ScavTrap(ScavTrap const& src);
		ScavTrap&		operator=(ScavTrap const &);

		void			challengeNewcomer(std::string const & target);
		typedef void(ScavTrap::*func)(std::string const &);
		static const func tab[];
		void			crystal(std::string const & target);
		void			glass(std::string const & target);
		void			ruby(std::string const & target);
		void			diamond(std::string const & target);
		void			emerald(std::string const & target);

	private:
		ScavTrap(void);
};

#endif