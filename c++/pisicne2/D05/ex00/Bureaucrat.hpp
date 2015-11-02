/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 12:26:03 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/13 15:17:01 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <stdexcept>
# include <iostream>

class Bureaucrat{
	private:
		std::string const	_name;
		int					_grade;
		Bureaucrat(void);
	class GradeTooHighException: public std::exception{
		public:
			GradeTooHighException(void);
			~GradeTooHighException(void) throw();
			GradeTooHighException(GradeTooHighException const &rhs);
			virtual const char* what() const throw();
		private:
			GradeTooHighException &operator=(GradeTooHighException const &src);
	};

	class GradeTooLowException: public std::exception{
		public:
			GradeTooLowException(void);
			~GradeTooLowException(void) throw();
			GradeTooLowException(GradeTooLowException const &rhs);
			virtual const char* what() const throw();
		private:
			GradeTooLowException &operator=(GradeTooLowException const &rhs);
	};

	public:
		Bureaucrat	&operator=(Bureaucrat const & src);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &rhs);
		std::string				const getName(void) const ;
		int						getGrade(void) const;
		void					incrementGrade(void);
		void					decrementGrade(void);
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif