/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 15:55:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/13 23:47:36 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"
# include "Bureaucrat.hpp"



Form::Form(std::string name, unsigned int gradeS, unsigned int gradeE): _name(name), _gradeS(gradeS), _gradeE(gradeE), _signed(false)
{
	if (gradeS > 150 || gradeE > 150)
		throw Form::GradeTooLowException();
	else if (gradeS < 1 || gradeE < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &rhs): _name(rhs._name), _gradeS(rhs._gradeS), _gradeE(rhs._gradeE), _signed(false)
{

}

Form::~Form(void)
{

}

void	Form::beSigned(Bureaucrat *br)
{
	if (br->getGrade() <= _gradeS && br->getGrade() <= _gradeE)
		_signed = true;
	else
		throw  Form::GradeTooLowException();

}

int				Form::getE(void) const
{
	return this->_gradeE;
}

int				Form::getS(void) const
{
	return this->_gradeS;
}

std::string		Form::getName(void) const
{
	return this->_name;
}

int				Form::getsign(void) const
{
	return this->_signed;
}

//GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(void){}
Form::GradeTooHighException::~GradeTooHighException(void) throw() {}

const char* 	Form::GradeTooHighException::what() const throw()
{
	return "The grade required is >= 1";
}

//GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(void){}
Form::GradeTooLowException::~GradeTooLowException(void) throw() {}

const char* 	Form::GradeTooLowException::what() const throw()
{
	return "The grade required is <= 150";
}

//func not member
std::ostream	&operator<<(std::ostream &o, Form const &rhs)
{
	if (rhs.getsign() == false)
		o << rhs.getName() << " is not a signed, a grade required to sign it: " << rhs.getS() << " and a grade required to execute: " << rhs.getE() << std::endl;
	else
		o << rhs.getName() << " is signed, a grade required to sign it: " << rhs.getS() << " and a grade required to execute: " << rhs.getE() << std::endl;
	return o;
}