/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 17:14:38 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 18:21:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP
# include "Brain.hpp"

class Human{

	public:
		Human(void);
		~Human(void);
		std::string	identify(void) const;
		Brain const &getBrain(void);

	private:
		Brain const _brain;
};

#endif