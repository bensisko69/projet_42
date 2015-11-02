/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 13:21:59 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/08 22:00:57 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & srcObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = srcObj;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = n << _fracBits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	int		intPart = f;
	float	decPart = f - intPart;

	this->_rawBits = intPart << _fracBits;
	for (int i = 1; i <= _fracBits; i++)
	{
		float	negPow = 1.0f / (1 << i);
		if (decPart >= negPow)
		{
			decPart -= negPow;
			this->_rawBits += (1 << (_fracBits - i));
			if (decPart == 0)
				break ;
		}
	}
}

Fixed&			Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
		this->_rawBits = rhs.getRawBits();
	return (*this);
}

int				Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void			Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}

float			Fixed::toFloat(void) const
{
	int		intPart = this->_rawBits >> _fracBits;
	float	decPart = 0;

	for (int i = 0; i < _fracBits; i++)
	{
		if (this->_rawBits & (1 << i))
		{
			int	negPow = _fracBits - i;
			decPart += 1.0f / (1 << negPow);
		}
	}
	return (intPart + decPart);
}

int				Fixed::toInt(void) const
{
	return (this->_rawBits >> _fracBits);
}

std::ostream&	operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return (os);
}
