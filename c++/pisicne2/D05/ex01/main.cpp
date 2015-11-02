/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:26:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/13 22:58:37 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	testBureaucrates()
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
		std::cout << std::endl << "Creating rank 151 Bureaucrat" << std::endl;
		d = new Bureaucrat("Gilbert", 151);
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
}

void	testForms()
{
	Form *a = 0;
	Form *a2 = 0;
	Form *a3 = 0;
	Form *b = 0;
	Form *c = 0;
	Bureaucrat br("Michel", 49);
	Bureaucrat br2("Michel", 50);
	Bureaucrat br3("Michel", 51);

	// Normal high rank
	try
	{
		std::cout << "Creating rank 50 Form" << std::endl;
		a = new Form("50F", 50, 50);
		a2 = new Form("50F2", 50, 50);
		a3 = new Form("50F3", 50, 50);
		std::cout << *a << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Normal low rank
	try
	{
		std::cout << "Creating rank 150 Form" << std::endl;
		b = new Form("150F", 150, 150);
		std::cout << *b << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Too high signing
	try
	{
		std::cout << "Creating rank 0 rank signing form" << std::endl;
		c = new Form("29A", 0, 150);
		std::cout << *c << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Too low signing
	try
	{
		std::cout << std::endl << "Creating rank 151 rank signing form" << std::endl;
		c = new Form("29A", 151, 150);
		std::cout << *c << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

		// Too high execute
	try
	{
		std::cout << std::endl << "Creating rank 0 rank execute form" << std::endl;
		c = new Form("29A", 150, 0);
		std::cout << *c << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Too low execute
	try
	{
		std::cout << std::endl << "Creating rank 151 rank execute form" << std::endl;
		c = new Form("29A", 150, 151);
		std::cout << *c << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Normal signing (higher)
	try
	{	
		if (a != NULL)
		{
			std::cout << std::endl << br;
			std::cout << *a;
			br.signeForm(*a);
			std::cout << *a << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Normal signing (equal)
	try
	{
		if (a2 != NULL)
		{
			std::cout << std::endl << br2;
			std::cout << *a2;
			br2.signeForm(*a2);
			std::cout << *a2 << std::endl;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}

	// Lower signing
	try
	{
		if (a3 != NULL)
		{
			std::cout << std::endl << br3;
			std::cout << *a3;
			br3.signeForm(*a3);
			std::cout << *a3;

		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << '\n';
	}
}

int		main(int, char **)
{
	// testBureaucrates();
	testForms();
	return (0);
}