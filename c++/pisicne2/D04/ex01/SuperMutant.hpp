/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 15:11:13 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP
#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy{
	public:
		SuperMutant(void);
		virtual ~SuperMutant(void);
		SuperMutant(SuperMutant const &src);
		SuperMutant &operator=(SuperMutant const &rhs);
		virtual void		takeDamage(int nb);
};

#endif