/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 10:48:46 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:45:06 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP
#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {
	public:
		Peon(std::string name);
		Peon(Peon const &src);
		~Peon(void);
		Peon &operator=(Peon const &rhs);
		virtual void	getPolymorphed(void) const;

	private:
		Peon(void);

};

#endif