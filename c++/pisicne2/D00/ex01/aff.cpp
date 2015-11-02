/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 13:26:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/06 18:36:47 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.class.hpp"

void				Awesome::aff_id(int id)
{
	std::cout << "Id = "<< id << std::endl;
	std::cout << "First name  = " << first_name << std::endl;
	std::cout << "Last name = " << last_name << std::endl;
	std::cout << "Nickname = " << nickname << std::endl;
	std::cout << "Login = " << login << std::endl;
	std::cout << "Postal adress = " << postal_adresse << std::endl;
	std::cout << "Email = " << email_adress << std::endl;
	std::cout << "Phone = " << phone_number << std::endl;
	std::cout << "Birthday = " << birthday_date << std::endl;
	std::cout << "Favorite meal = " << favorite_meal << std::endl;
	std::cout << "Underwear color = " << underwear_color << std::endl;
	std::cout << "Secret = " << secret << std::endl;
}

static void			aff_string(std::string str)
{

	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
	{
		std::cout << std::setw(10);
		std::cout << str;
	}
}

void				Awesome::aff(int j)
{
	std::cout << std::setw(10);
	std::cout << j << "|";
	aff_string(first_name);
	std::cout << "|";
	aff_string(last_name);
	std::cout << "|";
	aff_string(nickname);
	std::cout << "|";
	std::cout << std::endl;
}
