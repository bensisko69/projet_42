/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:12 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 15:06:24 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form{

	public: 
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);
		void		execute(Bureaucrat const & executor) const;
		void		action(void) const;
		class FormNoSign: public std::exception{
			public:
				FormNoSign(void);
				~FormNoSign(void) throw();
				virtual const char* what() const throw();
				FormNoSign(FormNoSign const &rhs);
			private:
				FormNoSign &operator=(FormNoSign const &src);
		};
	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

};

#endif // SHRUBBERYCREATIONFORM_HPP
