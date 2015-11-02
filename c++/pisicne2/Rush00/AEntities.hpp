/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntities.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wburgos <wburgos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/11 17:56:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/12 23:16:08 by wburgos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ENTITIES_HPP
# define A_ENTITIES_HPP

#include <iostream>
#include <ncurses.h>

# define RED 1
# define YELLOW 2
# define CYAN 3
# define WHITE 4

class AEntities
{
private:
	AEntities(void);

protected:
	WINDOW const *		_win;
	int					_x, _y;
	int					_winwidth, _winheight;
	char				_char;
	AEntities * 		_missile;
	int					_color;

public:

	AEntities(WINDOW const * win, int x, int y, char caract, int color);
	virtual ~AEntities(void);
	AEntities(AEntities const &src);

	AEntities &operator=(AEntities const & rhs);

	virtual void		movement() = 0;
	virtual void		update(void) = 0;

	void				draw(void);
	void				del(void);

	bool				impact(AEntities * entities) const;

	int					getX(void) const;
	int					getY(void) const;
	char				getChar(void) const;
	AEntities *			getMissile(void) const;

	static int			loopCount;
};

#endif
