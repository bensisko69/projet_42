/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:32:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/17 15:19:46 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n): _maxSize(n)
{

}

Span::Span(Span const &src): _lst(src._lst), _maxSize(src._maxSize)
{

}

Span &Span::operator=(Span const &rhs)
{
	this->_lst = rhs._lst;
	this->_maxSize = rhs._maxSize;
	return *this;
}

Span::~Span(void)
{

}

void	Span::addNumber(unsigned int nbr)
{
	std::vector<unsigned int>::const_iterator	it = _lst.begin();
	if (_lst.size() < _maxSize)
	{
		for(; it != _lst.end() && *it <= nbr; it++);
		_lst.insert(it, nbr);
	}
	else
		throw MaxSize();
}

unsigned int	Span::shortestSpan(void)
{
	unsigned int tmp = 4200000;
	unsigned int tmp2 = 0;

	std::vector<unsigned int>::const_iterator	it = _lst.begin();
	std::vector<unsigned int>::const_iterator	ite = _lst.begin() + 1;
	for(; ite != _lst.end(); ite++)
	{
		tmp2 = (*ite - *it);
		if (tmp > tmp2)
		{
			tmp = tmp2;
		}
		it++;
	}
	return tmp;
}

unsigned int	Span::longestSpan(void)
{
	if (_lst.size() > 2)
		return ((*(_lst.end() - 1) - *(_lst.begin())));
	return 0;
}


//exception
Span::MaxSize::MaxSize(void){}

Span::MaxSize::~MaxSize(void) throw(){}

const char* Span::MaxSize::what() const throw()
{
	return "Insert max size vector";
}
