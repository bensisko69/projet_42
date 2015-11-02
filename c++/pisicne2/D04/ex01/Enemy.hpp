/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 13:47:07 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/11 14:24:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <iostream>

class Enemy
{
	public:
		Enemy(int hp, std::string const & type);
		virtual ~Enemy();
		Enemy(Enemy const &src);
		std::string const	&getType() const;
		int					getHP() const;
		virtual void		takeDamage(int nb);
		Enemy &operator=(Enemy const &rhs);

	private:
		Enemy(void);
		int					_hp;
		std::string 		_type;
};

#endif