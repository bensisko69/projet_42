/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 15:13:07 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", target, 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form(src)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

void	ShrubberyCreationForm::action(void) const
{
	std::string str = this->getTarget() + "_shrubbery";
	std::ofstream	file;
	file.open(str);
	file << "          &&& &&  & &&" << std::endl;
	file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
	file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	file << "     &&     \\|||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "             |||" << std::endl;
	file << "       , -=-~  .-^- _" << std::endl;
	file << "              `" << std::endl;

	file.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getsign() == false)
		throw ShrubberyCreationForm::FormNoSign();
	if (executor.getGrade() > this->getE())
		throw Form::GradeTooLowException();
	action();
}

ShrubberyCreationForm::FormNoSign::FormNoSign(void){}

ShrubberyCreationForm::FormNoSign::~FormNoSign(void) throw(){}

const char* ShrubberyCreationForm::FormNoSign::what() const throw()
{
	return "You cannot execute an unsigned form";
}
