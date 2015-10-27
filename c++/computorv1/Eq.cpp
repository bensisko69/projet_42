/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eq.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 21:30:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/06/01 19:22:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Eq.hpp"

Equation::Equation(Polynom const &left, Polynom const &right):
	_left(left), _right(right), _reductForm(left), _delta(0), _res1(0), _res1i(0), _res2(0), _res2i(0)
{

}

Equation::~Equation(void)
{

}

double		Equation::racine(double nbr) const
{
	double	x0 = 1;

	for (int i = 0; i < 20; i++)
		x0 = (x0 - ((x0 * x0) - nbr) / (2 * x0));
	return x0;
}

void		Equation::delta(void)
{
	_delta = _reductForm.b() * _reductForm.b() - 4 * _reductForm.a() * _reductForm.c();
	if (_delta < 0)
	{
		_res1 = -_reductForm.b() / (2 * _reductForm.a());
		_res1i = racine(-_delta) / (2  * _reductForm.a());
		_res2 = -_reductForm.b() / (2 * _reductForm.a());
		_res2i = racine(-_delta) / (2  * _reductForm.a());
	}
	if (_delta == 0)
		_res1 = -_reductForm.b() / (2 * _reductForm.a());
	else if (_delta > 0)
	{
		_res1 = (-_reductForm.b() + racine(_delta)) / (2  * _reductForm.a());
		_res2 = (-_reductForm.b() - racine(_delta)) / (2  * _reductForm.a());
	}
}

void	Equation::resolv(void)
{
	_res1 = -_reductForm.c() / _reductForm.b();
}

void	Equation::reduc(void)
{
	for (auto it = _right._terms.begin(); it != _right._terms.end(); it++) {
		std::cout << _reductForm << " = " << _right << std::endl;
		_reductForm._terms[it->first] -= it->second;
		it->second = 0;
	}
	std::cout << "Reduced form: " << _reductForm << " = 0" << std::endl;
	std::cout << "Polynomial degree: " << _reductForm.degree() << std::endl;
	std:: cout << "The polynomial degree is stricly greater than 2, I can't solve.";
}

void		Equation::solve(void)
{
	if (_left.degree() <= 2 && _right.degree() <= 2)
	{
		_vec.emplace_back(_reductForm, _right);
		_reductForm.c() = _left.c() - _right.c();

		if (_right.c()) {
			_right.c() = 0;
			_vec.emplace_back(_reductForm, _right);
		}

		_reductForm.b() = _left.b() - _right.b();
		if (_right.b()) {
			_right.b() = 0;
			_vec.emplace_back(_reductForm, _right);
		}

		_reductForm.a() = _left.a() - _right.a();
		if (_reductForm.a() != 0)
			delta();
		else if(_reductForm.a() == 0 && _reductForm.b() == 0 && _reductForm.c() != 0)
		{
			std::cout << "I can't solve." << std::endl;
			exit(0);
		}
		else if(_reductForm.a() == 0 && _reductForm.b() == 0 && _reductForm.c() == 0)
		{
			std::cout << _left.c() << " = " << _right.c() << std::endl;
			std::cout << "S = { R }" << std::endl;
			exit(0);
		}
		else if (_reductForm.a() == 0)
			resolv();
		display();
	}
	else
		reduc();
}

void		Equation::display0() const
{
	for (auto it = _vec.begin(); it != _vec.end(); it++)
		std::cout << it->first << " = " << it->second << std::endl;
	std::cout << "Reduced form: " << _reductForm << " = 0"<< std::endl;
	std::cout << "Polynomial degree: 1" << std::endl;
	std::cout << "x1 = " << -_reductForm.c() << " / " << _reductForm.b() << std::endl;
	std::cout << "x1 = " << _res1;
}

void		Equation::display() const
{
	if (_reductForm.a() != 0)
	{
		for (auto it = _vec.begin(); it != _vec.end(); it++)
			std::cout << it->first << " = " << it->second << std::endl;
		std::cout << "Reduced form: " << _reductForm << " = 0"<< std::endl;
		std::cout << "Polynomial degree: 2" << std::endl;
		std::cout << "Delta = " << _reductForm.b() << "^2 - 4 * " << _reductForm.a() << " * " << _reductForm.c() << std::endl;
		std::cout << "Delta = " << _delta << std::endl;
		if (_delta < 0)
		{
			std::cout << "Discriminant is strictly negative, the two solutions are:" << std::endl;
			std::cout << "x1 = " << _res1 << " "<< -_res1i << "i" << std::endl;
			std::cout << "x2 = " << _res2 << " + " << _res2i << "i";
		}
		else if (_delta == 0)
			std::cout << "The solution is: " << _res1;
		else
		{
			std::cout << "Discriminant is strictly positive, the two solutions are: " << std::endl;
			std::cout << "x1 = " << "(" << _reductForm.b() << " + " << racine(_delta) << ") / (2 * " << _reductForm.a() << ")" << std::endl;
			std::cout << "x2 = " << "(" << _reductForm.b() << " - " << racine(_delta) << ") / (2 * " << _reductForm.a() << ")" << std::endl;
			std::cout << "x1: " << _res1 << std::endl;
			std::cout << "x2: " << _res2;
		}
	}
	else if (_reductForm.a() == 0)
		display0();
}