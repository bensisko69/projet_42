/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 18:54:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 19:20:46 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>

class Weapon{

	public:
		Weapon(void);
		Weapon(std::string str);
		~Weapon(void);

		std::string const &getType(void) const;
		void				setType(std::string const type);

	private:
		std::string _type;
};

#endif