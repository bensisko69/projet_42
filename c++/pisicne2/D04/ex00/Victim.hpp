/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 13:36:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP
#include <iostream>

class Victim{

	public:
		Victim(std::string name);
		Victim(Victim const &src);
		virtual ~Victim(void);
		Victim &operator=(Victim const &rhs);
		std::string	getName(void) const;
		void		setName(std::string name);
		virtual void	getPolymorphed(void) const;

	private:
		Victim(void);
		std::string _name;

};

std::ostream & operator<<(std::ostream &o, Victim const &rhs);

#endif