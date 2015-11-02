/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 15:17:44 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): Form(src)
{

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getsign() == false)
		throw RobotomyRequestForm::FormNoSign();
	if (executor.getGrade() > this->getE())
		throw Form::GradeTooLowException();
	if ((rand() % 2) == 0)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomization on " << this->getTarget() << " has failed." << std::endl;
}


RobotomyRequestForm::FormNoSign::FormNoSign(void){}

RobotomyRequestForm::FormNoSign::~FormNoSign(void) throw(){}

const char* RobotomyRequestForm::FormNoSign::what() const throw()
{
	return "You cannot execute an unsigned form";
}
