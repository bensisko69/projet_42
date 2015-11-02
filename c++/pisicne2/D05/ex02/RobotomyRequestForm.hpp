/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 23:15:31 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/14 14:39:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <fstream>
# include "Form.hpp"

class RobotomyRequestForm: public Form{

	public: 
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);
		void	execute(Bureaucrat const & executor) const;
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
		RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

};

#endif // ROBOTOMYREQUESTFORM_HPP
