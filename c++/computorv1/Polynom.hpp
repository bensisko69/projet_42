/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 15:37:32 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/05/31 22:06:12 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOM_HPP
# define POLYNOM_HPP
# include <iostream>
# include <map>

class Polynom{
	public:
		using Terms = std::map<uint, double>;
		Polynom(Terms);
		Polynom(void);
		~Polynom(void);
		uint	degree(void) const;
		double	&a(void);
		double	&b(void);
		double	&c(void);
		double	a(void) const;
		double	b(void) const;
		double	c(void) const;
		void	display(std::ostream & os) const;
		Terms	_terms;
};

std::ostream	&operator<<(std::ostream &o, Polynom const &rhs);

#endif // POLYNOM_HPP
