/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:56:19 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:33:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class NinjaTrap : public virtual ClapTrap
{
	public:
		NinjaTrap(std::string name);
		~NinjaTrap();
		NinjaTrap(NinjaTrap const& src);
		NinjaTrap&		operator=(NinjaTrap const &);

		void	ninjaShoebox(FragTrap &src);
		void	ninjaShoebox(NinjaTrap &src);
		void	ninjaShoebox(ScavTrap &src);

	protected:
		NinjaTrap(void);
};

#endif

