/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 13:06:29 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/06 16:36:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.class.hpp"

void	Awesome::add(void)
{
	std::cout << "Enter your first name : ";
	std::getline(std::cin, first_name);
	std::cout << "Enter your last name : ";
	std::getline(std::cin, last_name);
	std::cout << "Enter your nickname : ";
	std::getline(std::cin, nickname);
	std::cout << "Enter your login : ";
	std::getline(std::cin, login);
	std::cout << "Enter your Postal adress : ";
	std::getline(std::cin, postal_adresse);
	std::cout << "Enter your email : ";
	std::getline(std::cin, email_adress);
	std::cout << "Enter your phone number : ";
	std::getline(std::cin, phone_number);
	std::cout << "Enter your birthday date : ";
	std::getline(std::cin, birthday_date);
	std::cout << "Enter favorite meal : ";
	std::getline(std::cin, favorite_meal);
	std::cout << "Enter underwear color : ";
	std::getline(std::cin, underwear_color);
	std::cout << "Enter your secret : ";
	std::getline(std::cin, secret);
}