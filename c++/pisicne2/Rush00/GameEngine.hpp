/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 22:53:29 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEENGINE_HPP
# define GAMEENGINE_HPP

# include <ncurses.h>
# include <unistd.h>
# include <cstdlib>
# include "Player.hpp"
# include "Enemy.hpp"
# include "Asteroids.hpp"
# include <fstream>

# define ENTITIES_MAX	1000
# define EASY			100
# define HARD			8
# define DODGE			3
# define CHEAT			1

class GameEngine
{
public:
	GameEngine(void);
	~GameEngine(void);

	bool					render(void);
	bool					updateEntities(void);

	void					drawEntities(void);
	AEntities *				getEntity(int n) const;
	void					addEntity(AEntities * entity);
	WINDOW const *			getWindow(void) const;
	void					printEntities(void);
	static int							i;

private:
	GameEngine(GameEngine const &src);
	GameEngine	&operator=(GameEngine const &src);

	bool					playerColision(void);
	void					entityColision(void);
	void					deleteEntity(AEntities * entity);

	WINDOW const *				_win;
	int							_winheight;
	int							_winwidth;
	Player *					_p1;
	AEntities *					_entities[ENTITIES_MAX];
	static int					_score;
};

#endif
