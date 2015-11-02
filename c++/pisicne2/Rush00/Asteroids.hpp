/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/12 20:19:44 by wburgos           #+#    #+#             */
/*   Updated: 2015/04/12 20:20:16 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_HPP
# define ASTEROIDS_HPP

# include "AEntities.hpp"

class Asteroids: public AEntities
{
	public:
		Asteroids(WINDOW const * win, int x, int y);
		~Asteroids(void);
		Asteroids(Asteroids const &src);
		Asteroids			&operator=(Asteroids const &rhs);

		void			update(void);
		void			movement(void);

	private:
		Asteroids(void);
};

#endif
