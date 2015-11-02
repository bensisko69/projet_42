/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 11:43:56 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/06 18:14:34 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_CLASS_HPP
# define AWESOME_CLASS_HPP
#include <iostream>
#include <iomanip>

class Awesome {
	std::string first_name, last_name, nickname, login, postal_adresse, email_adress,
				phone_number, birthday_date, favorite_meal, underwear_color, secret;

	public:
		Awesome(void);
		~Awesome(void);
		void	add(void);
		void	aff(int j);
		void	aff_id(int ID);

};


#endif