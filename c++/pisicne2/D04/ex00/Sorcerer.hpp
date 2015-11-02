/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 12:05:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP
#include <iostream>
#include "Victim.hpp"

class Sorcerer{

	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);
		Sorcerer &operator=(Sorcerer const &rhs);
		std::string	getName(void) const;
		std::string	getTitle(void) const;
		void polymorph(Victim const &o) const;

	private:
		std::string _name, _title;
		Sorcerer(void);

};

std::ostream & operator<<(std::ostream &o, Sorcerer const &rhs);

#endif