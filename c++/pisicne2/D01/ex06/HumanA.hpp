/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 18:54:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 20:04:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA{

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void	attack();

	private:
		std::string _name;
		Weapon &_weapon;
};

#endif