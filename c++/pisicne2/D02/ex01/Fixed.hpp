/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 13:21:59 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/08 22:00:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(Fixed const &);
	Fixed(int const);
	Fixed(float const);
	~Fixed(void);

	Fixed& 				operator=(Fixed const &rhs);

	int					getRawBits(void) const;
	void				setRawBits(int const);

	float				toFloat(void) const;
	int					toInt(void) const;

private:
	int					_rawBits;
	static int const	_fracBits = 8;

};

std::ostream& 	operator<<(std::ostream&, Fixed const &);

#endif
