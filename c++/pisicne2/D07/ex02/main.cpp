/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 17:04:34 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/15 21:59:26 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "array.hpp"

template <typename T>
void showArray(const Array<T> & array) {
	for (unsigned i = 0; i < array.size(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

int main() 
{
	const Array<int> constArray(10);
	Array<int> arrayCopied(constArray);
	Array<int> arrayAssigned;

	showArray(constArray);
	std::cout << "size constArray " << constArray.size() << std::endl;
	std::cout << std::endl;

	std::cout << "size arrayCopied " << arrayCopied.size() << std::endl;
	showArray(arrayCopied);
	std::cout << std::endl;

	std::cout << "assigning values to arrayCopied" << std::endl;
	for (unsigned i = 0; i < arrayCopied.size(); i++)
		arrayCopied[i] = i;
	showArray(arrayCopied);
	std::cout << "constArray did not change: ";
	showArray(constArray);
	std::cout << std::endl;
	
	std::cout << "size arrayAssigned " << arrayAssigned.size() << std::endl;
	std::cout << "assigning arrayAssigned" << std::endl;
	arrayAssigned = arrayCopied;
	std::cout << "size arrayAssigned after assignation: " << arrayAssigned.size() << std::endl;
	showArray(arrayAssigned);
	std::cout << std::endl;

	std::cout << "trying to show up to 1000 elements of arrayAssigned" << std::endl;
	for (unsigned i = 0; i < 1000; ++i) {
		try {
			std::cout << i << " th element: " << arrayAssigned[i] << std::endl;
		}
		catch(const std::exception & e) {
			std::cerr << " could not display " << i << " th element because:" 
					  << e.what() << std::endl;
			break ;
		}
	}
	return 0;
}
