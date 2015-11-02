/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:26:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/13 23:06:48 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();

}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat::Bureaucrat(Bureaucrat const &rhs): _name(rhs._name), _grade(rhs._grade)
{

}

Bureaucrat	& Bureaucrat::operator=(Bureaucrat const & src)
{
	this->_grade = src._grade;
	return *this;
}

std::string			const Bureaucrat::getName(void) const
{
	return this->_name;
}

int						Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void					Bureaucrat::incrementGrade(void)
{
	if (_grade > 0)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
}

void					Bureaucrat::decrementGrade(void)
{
	if (_grade < 150)
		this->_grade++;
	else 
		throw Bureaucrat::GradeTooHighException();
}


//GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(void){}
Bureaucrat::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char* 	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade required is >= 1";
}

//GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(void){}
Bureaucrat::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade required is <= 150";
}

//func not member
std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.getName() << " , bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return o;
}
