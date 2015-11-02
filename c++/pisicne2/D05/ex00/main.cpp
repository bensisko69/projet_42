/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:26:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/13 15:15:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int        main(int, char **)
{
	Bureaucrat *a;
	Bureaucrat *b;
	Bureaucrat *c;
	Bureaucrat *d;

	// Normal high rank
	try
	{
		std::cout << "Creating rank 1 Bureaucrat" << std::endl;
		a = new Bureaucrat("Chief", 1);
		std::cout << *a << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Normal low rank
	try
	{
		std::cout << "Creating rank 150 Bureaucrat" << std::endl;
		b = new Bureaucrat("Larbin", 150);
		std::cout << *b << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Too high
	try
	{
		std::cout << "Creating rank 0 Bureaucrat" << std::endl;
		c = new Bureaucrat("Gilbert", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Too low
	try
	{
		std::cout << std::endl << "Creating rank 200 Bureaucrat" << std::endl;
		d = new Bureaucrat("Gilbert", 200);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Normal incrementGrade/decrementGrade
	try
	{
		std::cout << std::endl << "Normal incrementGrade/decrementGrade" << std::endl;
		a->decrementGrade();
		std::cout << *a << std::endl;
		a->incrementGrade();
		std::cout << *a << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// incrementGrade on high
	try
	{
		std::cout << "Upgrading rank 1 Bureaucrat" << std::endl;
		a->incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// decrementGrade on low
	try
	{
		std::cout << std::endl << "Downgrading rank 150 Bureaucrat" << std::endl;
		b->decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}
	return (0);
}