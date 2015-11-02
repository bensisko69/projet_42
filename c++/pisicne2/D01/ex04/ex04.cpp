/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 15:59:36 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 16:11:20 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int, char **)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *strPt = &str;
	std::string &strref = str;

	std::cout << "Print str = " << str << std::endl;
	std::cout << "Print pointer = " << *strPt << std::endl;
	std::cout << "Print reference = " << strref << std::endl;
	return (0);
}