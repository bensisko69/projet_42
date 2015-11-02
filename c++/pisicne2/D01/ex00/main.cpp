/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/07 11:35:02 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/07 12:14:09 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void	ponyOnTheHeap(std::string name, std::string allocate)
{
	Pony	*bob = new Pony(name, allocate);
	delete bob;
}

void	ponyOnTheStack(std::string name, std::string allocate)
{
	Pony	bill = Pony(name, allocate);
}

int	main(void)
{
	ponyOnTheHeap("Bob", "on the heap");
	ponyOnTheStack("Bill", "on the stack");

	return 0;
}