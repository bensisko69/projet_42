/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 22:22:35 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 23:05:19 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP
#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy{
	public:
		RadScorpion(void);
		virtual ~RadScorpion(void);
		RadScorpion(RadScorpion const &src);
		RadScorpion &operator=(RadScorpion const &rhs);
		virtual void		attack() const;
};

#endif