/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 15:55:10 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 15:00:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
class Bureaucrat;

class Form{
	public:
		Form(std::string name, std::string target, unsigned int gradeS, unsigned int gradeE);
		virtual ~Form(void);
		Form(Form const &src);
		void			beSigned(Bureaucrat *br);
		std::string		getName(void) const;
		int				getE(void) const;
		int				getsign(void) const;
		int				getS(void) const;
		std::string		getTarget(void) const;
		virtual void			execute(Bureaucrat const & executor) const = 0;

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

	private:
		Form	&operator=(Form const & src);
		Form(void);
		std::string const	_name, _target;
		int			const	_gradeS, _gradeE;
		bool				_signed;

};

std::ostream	&operator<<(std::ostream &o, Form const &rhs);

#endif // FORM_HPP
