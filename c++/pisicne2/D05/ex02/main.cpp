/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:26:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 14:54:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void	unsignedTest()
{
	ShrubberyCreationForm f("unsigned_target");
	Bureaucrat b("Obama", 1);

	std::cout << f;
	b.executeForm(f);
}

void	badExecTest()
{
	ShrubberyCreationForm f("random_target");
	Bureaucrat b("Obama", 1);
	Bureaucrat b2("Cyprien", 150);

	b.signForm(f);
	std::cout << f;
	std::cout << b2;
	b2.executeForm(f);
}

void	robotomy()
{
	RobotomyRequestForm f("robotomy_target");
	Bureaucrat b("Obama", 1);

	b.signForm(f);
	std::cout << f;
	b.executeForm(f);
}

void	shrubbery()
{
	ShrubberyCreationForm f("shrubbery_target");
	Bureaucrat b("Obama", 1);

	b.signForm(f);
	std::cout << f;
	b.executeForm(f);
}

void	prez()
{
	PresidentialPardonForm f("prez_target");
	Bureaucrat b("Obama", 1);

	b.signForm(f);
	std::cout << f;
	b.executeForm(f);
}

int		main(int, char **)
{
	srand(time(0));

	unsignedTest();
	std::cout << std::endl;
	badExecTest();
	std::cout << std::endl;
	robotomy();
	std::cout << std::endl;
	shrubbery();
	std::cout << std::endl;
	prez();

	return (0);
}