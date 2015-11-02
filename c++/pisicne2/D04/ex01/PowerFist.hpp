/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:47:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
#define POWERFIST_HPP
#include <iostream>
#include "AWeapon.hpp"

class PowerFist: public AWeapon{
	public:
		PowerFist(void);
		~PowerFist(void);
		PowerFist &operator=(PowerFist const &rhs);
		PowerFist(PowerFist const &src);
		void		attack() const;
};

#endif