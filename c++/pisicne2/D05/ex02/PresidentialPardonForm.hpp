/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:51 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 14:39:50 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP
#include <fstream>
# include "Form.hpp"

class PresidentialPardonForm: public Form{

	public: 
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);
		void	execute(Bureaucrat const & executor) const;
		void	action(Bureaucrat const & executor);
		class FormNoSign: public std::exception{
			public:
				FormNoSign(void);
				~FormNoSign(void) throw();
				FormNoSign(FormNoSign const &rhs);
				virtual const char* what() const throw();
			private:
				FormNoSign &operator=(FormNoSign const &src);
		};
	private:
		PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

};

#endif // PRESIDENTIAL_PARDON_FORM_HPP
