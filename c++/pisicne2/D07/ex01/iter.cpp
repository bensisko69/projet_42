/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 16:16:33 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/15 22:42:53 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

// template<typename T, typename Size>
// void	iter(T *array, Size size, void (*func)(const T &))
// {
// 	for(Size i = 0; i < size; i++)
// 		func(array[i]);
// }

template<typename T, typename Size, typename F>
void	iter(T *array, Size size, const F & func)
{
	for(Size i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void	aff(const T & a)
{
	std::cout << a << " ";
}

struct Afficheur {
	Afficheur (char separator): sep(separator) { }

	template <typename T>
	void operator()(T & value) const {
		std::cout << value << sep;
	}
	char sep;
};

struct Custom {
	Custom(int i):i(i) { }
	int i;
};

std::ostream & operator<<(std::ostream & os, const Custom & c)
{
	return os << c.i;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	Afficheur afficheur(*argv[1]);

	int	tab[4] = { 2, 1, 6, 5 };
	iter(tab, 4, afficheur);
	std::cout << std::endl;
	iter(tab, 4, aff<int>);
	std::cout << std::endl;

	Custom customTab[5] = { 0, 6, 7, 1, 4 };
	iter(customTab, 5ul, afficheur);
	std::cout << std::endl;
	iter(customTab, 5ul, aff<Custom>);
	std::cout << std::endl;
	return 0;
}