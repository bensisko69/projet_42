/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Eq.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 21:30:41 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/05/31 22:27:30 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQ_HPP
# define EQ_HPP
# include <iostream>
# include "Polynom.hpp"
# include <vector>
using Tpair = std::pair<Polynom, Polynom>;
using Tvector = std::vector<Tpair>;

class Equation{
	public:
		Equation(Polynom const &left, Polynom const &right);
		Equation(void) = default;
		~Equation(void);
		void		solve(void);
		void		delta(void);
		double		racine(double nbr) const;
		void		resolv(void);
		void		reduc(void);

	private:
		void		display() const;
		void		display0() const;
		Polynom	_left, _right, _reductForm;
		double	_delta, _res1, _res1i, _res2, _res2i;
		Tvector	_vec;
};

#endif // EQ_HPP
