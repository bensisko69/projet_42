/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:51 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 15:02:08 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): Form(src)
{

}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getsign() == false)
		throw PresidentialPardonForm::FormNoSign();
	if (executor.getGrade() > this->getE())
		throw Form::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl; 

}

PresidentialPardonForm::FormNoSign::FormNoSign(void){}

PresidentialPardonForm::FormNoSign::~FormNoSign(void) throw(){}

const char* PresidentialPardonForm::FormNoSign::what() const throw()
{
	return "You cannot execute an unsigned form";
}
