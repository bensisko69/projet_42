/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:32:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/17 20:59:27 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(int, char **)
{
	Span sp = Span(10000);
	int values[] = { 1, 2, 3, 42, 1337 };
	std::vector<int> values2(values, values + sizeof(values) / sizeof(int));
	try
	{
		for(int i = 0; i < 10000; i+=2)
			sp.addNumber(i);
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		sp.addNumber(values, values + sizeof(values) / sizeof(int));
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		sp.addNumber(values2.begin(), values2.end());
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		for(int i = 0; i < 10000; i+=2)
			sp.addNumber(i);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}