/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 20:21:49 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/09 15:43:54 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include <iostream>

class Human
{
	private:
		void meleeAttack(std::string const & target);
		void rangedAttack(std::string const & target);
		void intimidatingShout(std::string const & target);
		void error(std::string const & target);
		static const std::string array_name[];
		typedef void(Human::*func)(std::string const &);
		static const func tab[];
	public:
		void action(std::string const & action_name, std::string const & target);
		Human(void);
		~Human(void);
};

#endif
