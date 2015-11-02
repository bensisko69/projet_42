/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 11:51:54 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/15 13:43:42 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include <iostream>
class Base{
	public:
		virtual ~Base(void)
		{

		}
};

class A: public Base{
};

class B: public Base{

};

class C: public Base{

};

static Base	*generate(void)
{
	int i = (rand() %3);
	if (i == 0)
	{
		std::cout << "generate = A" << std::endl;
		return new A();
	}
	if (i == 1)
	{
		std::cout << "generate = B" << std::endl;
		return new B();
	}
	if (i == 2)
	{
		std::cout << "generate = C" << std::endl;
		return new C();
	}
	return	NULL;
}
void identify_from_pointer( Base * p )
{
	A	*a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << "Class A" << std::endl;
	B	*b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << "Class B" << std::endl;
	C	*c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << "Class C" << std::endl;
}

void identify_from_reference( Base & p )
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Class A whit ref" << std::endl;
	}
	catch (std::bad_cast &){}

	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Class B whit ref" << std::endl;
	}
	catch (std::bad_cast &e){}

	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Class C whit ref" << std::endl;
	}
	catch (std::bad_cast &e) {}
}

int main(int, char **)
{
	srand(time(0));
	Base *base = generate();
	identify_from_pointer(base);
	Base *base2 = generate();
	identify_from_reference(*base2);
	delete base;
	return 0;
}