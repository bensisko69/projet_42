/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 14:36:28 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/17 20:57:35 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>


template <class T, size_t N>
void	print(T const &container, int const (&toFind)[N])
{
	for (size_t i = 0; i < N; i++)
	{
		typename T::const_iterator it = easyfind(container, toFind[i]);
		if (it != container.end())
			std::cout << "Found " << toFind[i] << " at position: "
					  << std::distance(container.begin(), it) << std::endl;
		else
			std::cout << "Not Found: " << toFind[i] << std::endl;
	}
}

int	main(void)
{
	int values[] = { 1, 2, 3, 42, 1337 };
	int	valueCount = sizeof(values) / sizeof(int);
	int toFind[] = { 2, 35, 4200, 1337 };
	std::list<int>		lst(values, values + valueCount);
	std::vector<int>	vec(values, values + valueCount);
	std::deque<int>		dqe(values, values + valueCount);

	std::cout << "Container list" << std::endl;
	print(lst, toFind);
	std::cout << std::endl;
	std::cout << "Container deque" << std::endl;
	print(dqe, toFind);
	std::cout << std::endl;
	std::cout << "Container vector" << std::endl;
	print(vec, toFind);

	return 0;
}