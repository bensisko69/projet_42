/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 14:43:42 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 15:33:28 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
#include <iostream>
#include "Zombie.hpp"

class ZombieHorde{
	private:
		int 	_nbr;
		Zombie *_horde;

	public:
		ZombieHorde(int nb);
		~ZombieHorde(void);
};


#endif