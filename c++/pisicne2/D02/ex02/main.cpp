/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/08 13:22:09 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/08 23:42:45 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(1);
	Fixed c(3);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const d( 18.56f );

	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	std::cout << "C = " << c << std::endl;
	std::cout << "D = " << d << std::endl;
	std::cout << "Ope + " << (a + c) << std::endl;
	std::cout << "Ope - " << (a - c) << std::endl;
	std::cout << "Ope * " << (a * c) << std::endl;
	std::cout << "Ope / " << (a / c) << std::endl;
	std::cout << "Ope > " << (a > c) << std::endl;
	std::cout << "Ope < " << (a < c) << std::endl;
	std::cout << "Ope >= " << (a >= c) << std::endl;
	std::cout << "Ope <= " << (a <= c) << std::endl;
	std::cout << "Ope == " << (a == c) << std::endl;
	std::cout << "Ope != " << (a != c) << std::endl;
	std::cout << "Max = " << Fixed::max( a, c ) << std::endl;
	std::cout << "Max = " << Fixed::max( b, d ) << std::endl;
	std::cout << "Min = " << Fixed::min( a, c ) << std::endl;
	std::cout << "Min = " << Fixed::min( b, d ) << std::endl;

	return 0;
}