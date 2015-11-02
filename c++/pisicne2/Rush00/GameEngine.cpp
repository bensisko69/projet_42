/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameEngine.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 20:17:39 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 23:15:11 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
	initscr();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
	getmaxyx(stdscr, _winheight, _winwidth);
	_p1 = new Player(stdscr, 0, _winheight / 2);
	_win = stdscr;
	for (int i = 0; i < ENTITIES_MAX; i++)
		_entities[i] = 0;
}

GameEngine::~GameEngine(void)
{
	delete _p1;
	endwin();
	std::cout << "Game over. Score: " << GameEngine::_score << std::endl;
}

GameEngine::GameEngine(GameEngine const &src) :
_win(src._win), _winheight(src._winheight), _winwidth(src._winwidth)
{
}

GameEngine		&GameEngine::operator=(GameEngine const &src)
{
	if (this != &src)
		_win = src._win;
	return (*this);
}

bool				GameEngine::render(void)
{
	usleep(15000);
	mvprintw(0, 0, "Score: %d", _score);
	if (AEntities::loopCount == 101)
		AEntities::loopCount = 0;
	AEntities::loopCount++;
	if (rand() % GameEngine::i < 5)
	{
		int enY = rand() % _winheight;
		addEntity(new Enemy(_win, _winwidth, (enY == 0) ? 1 : enY));
		if (GameEngine::i == EASY)
		{
			int asY = rand() % _winheight;
			addEntity(new Asteroids(_win, _winwidth, (asY == 0) ? 1 : asY));
		}
	}
	if (!updateEntities())
		return (false);
	drawEntities();
	refresh();
	return (true);
}

AEntities * 		GameEngine::getEntity(int n) const
{
	return (_entities[n]);
}

void				GameEngine::drawEntities(void)
{
	_p1->draw();
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] != 0)
			_entities[i]->draw();
	}
}

void				GameEngine::addEntity(AEntities * entity)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] == 0)
		{
			_entities[i] = entity;
			return ;
		}
	}
}

bool				GameEngine::updateEntities(void)
{
	_p1->del();
	_p1->update();
	addEntity(_p1->getMissile());
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i])
		{
			_entities[i]->del();
			_entities[i]->update();
			addEntity(_entities[i]->getMissile());
		}
	}
	if (playerColision())
		return (false);
	entityColision();
	return (true);
}

void				GameEngine::deleteEntity(AEntities * entity)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if ( _entities[i] == entity)
		{
			if (_entities[i])
				delete _entities[i];
			_entities[i] = 0;
			return ;
		}
	}
}

bool				GameEngine::playerColision(void)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		if (_entities[i] && _p1->impact(_entities[i]))
			return (true);
	}
	return (false);
}

void				GameEngine::entityColision(void)
{
	for (int i = 0; i < ENTITIES_MAX; i++)
	{
		for (int j = i + 1; j < ENTITIES_MAX; j++)
		{
			if (_entities[i] && _entities[j] && _entities[i]->impact(_entities[j]))
			{
				_score += 50;
				deleteEntity(_entities[i]);
				deleteEntity(_entities[j]);
			}
		}
		if (_entities[i] && (_entities[i]->getX() < 0 || _entities[i]->getX() > 3000))
		{
			_score -= 10;
			deleteEntity(_entities[i]);
		}
	}
}

WINDOW const *		GameEngine::getWindow(void) const
{
	return (_win);
}

int			GameEngine::i = EASY;
int 		GameEngine::_score = 0;
