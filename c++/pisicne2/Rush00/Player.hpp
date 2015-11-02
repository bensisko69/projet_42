/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 20:46:16 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntities.hpp"

class Player : public AEntities
{
	public:
		Player(WINDOW const * win, int x, int y);
		~Player(void);
		Player(Player const &src);

		Player			&operator=(Player const &rhs);

		void			movement(void);
		void			update(void);
		void			shoot(void);

	private:
		Player(void);

		int			_input;
		int			_i;
};

#endif
