/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 11:19:57 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/10 22:26:38 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

	public:
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap(FragTrap const& src);
		FragTrap&		operator=(FragTrap const &);

		void		vaulthunter_dot_exe(std::string const & target);
		typedef void(FragTrap::*func)(std::string const &);
		static const func tab[];
		void			fire(std::string const & target);
		void			wind(std::string const & target);
		void			stone(std::string const & target);
		void			ice(std::string const & target);
		void			water(std::string const & target);

	private:
		FragTrap(void);
};

#endif