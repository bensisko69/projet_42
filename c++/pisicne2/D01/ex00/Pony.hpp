/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 11:35:02 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 12:10:21 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP
#include <iostream>

class Pony{
	private:
		std::string _name, _allocate;

	public:
		Pony(std::string name, std::string allocate);
		~Pony(void);
};

#endif