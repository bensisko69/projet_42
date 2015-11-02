/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 13:21:59 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/08 23:39:27 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const & srcObj)
{
	*this = srcObj;
}

Fixed::Fixed(int const n)
{
	this->_rawBits = n << _fracBits;
}

Fixed::Fixed(float const f)
{
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

Fixed&			Fixed::operator=(Fixed const & src)
{
	if (this != &src)
		this->_rawBits = src.getRawBits();
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

bool			Fixed::operator>(Fixed const &rhs)
{
	if (this->toFloat() > rhs.toFloat())
		return true;
	else
		return false;
}

bool			Fixed::operator<(Fixed const &rhs)
{
	if (this->toFloat() < rhs.toFloat())
		return true;
	else
		return false;
}

bool			Fixed::operator>=(Fixed const &rhs)
{
	if (this->toFloat() >= rhs.toFloat())
		return true;
	else
		return false;
}

bool			Fixed::operator<=(Fixed const &rhs)
{
	if (this->toFloat() <= rhs.toFloat())
		return true;
	else
		return false;
}

bool			Fixed::operator==(Fixed const &rhs)
{
	if (this->toFloat() == rhs.toFloat())
		return true;
	else
		return false;
}

bool			Fixed::operator!=(Fixed const &rhs)
{
	if (this->toFloat() != rhs.toFloat())
		return true;
	else
		return false;
}

Fixed&			Fixed::operator+(Fixed const &rhs)
{
	float	f;

	f = this->toFloat() + rhs.toFloat();
	Fixed *newFixed = new Fixed(f);
		return *newFixed;
}

Fixed&			Fixed::operator-(Fixed const &rhs)
{
	float	f;

	f = this->toFloat() - rhs.toFloat();
	Fixed *newFixed = new Fixed(f);
		return *newFixed;
}

Fixed&			Fixed::operator/(Fixed const &rhs)
{
	float	f;

	f = this->toFloat() / rhs.toFloat();
	Fixed *newFixed = new Fixed(f);
		return *newFixed;
}

Fixed&			Fixed::operator*(Fixed const &rhs)
{
	float	f;

	f = this->toFloat() * rhs.toFloat();
	Fixed *newFixed = new Fixed(f);
		return *newFixed;
}

Fixed&			Fixed::max(Fixed &val1, Fixed &val2)
{
	if (val1.toFloat() > val2.toFloat())
		return val1;
	return val2;
}

Fixed&			Fixed::min(Fixed &val1, Fixed &val2)
{
	if (val1.toFloat() > val2.toFloat())
		return val2;
	return val1;
}

Fixed const&	Fixed::max(Fixed const& val1, Fixed const& val2)
{
	if (val1.toFloat() > val2.toFloat())
		return val1;
	return val2;
}

Fixed const&	Fixed::min(Fixed const& val1, Fixed const& val2)
{
	if (val1.toFloat() > val2.toFloat())
		return val2;
	return val1;
}
