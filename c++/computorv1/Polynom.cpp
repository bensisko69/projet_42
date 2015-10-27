/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/26 15:37:32 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/05/31 22:34:41 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Polynom.hpp"
# include <vector>
# include <string>

Polynom::Polynom(Terms terms): _terms(terms)
{

}

Polynom::Polynom(void)
{

}

Polynom::~Polynom(void)
{

}

double	&Polynom::a(void)
{
	return _terms[2];
}

double	&Polynom::b(void)
{
	return _terms[1];
}

double	&Polynom::c(void)
{
	return _terms[0];
}

double	Polynom::a(void) const
{
	auto it = _terms.find(2);
	if (it == _terms.end())
		return 0;
	return it->second;
}

double	Polynom::b(void) const
{
	auto it = _terms.find(1);
	if (it == _terms.end())
		return 0;
	return it->second;
}

double	Polynom::c(void) const
{
	auto it = _terms.find(0);
	if (it == _terms.end())
		return 0;
	return it->second;
}



uint	Polynom::degree() const
{
	auto compareOnKey = [] (const auto &lhs, const auto & rhs){
		 return (lhs.first < rhs.first);
	};
	auto maxIt = std::max_element(_terms.begin(), _terms.end(), compareOnKey);
	if (maxIt == _terms.end())
		return 0;
	return maxIt->first;
}

void		Polynom::display(std::ostream &os) const
{

	struct Product { double value; std::string suffix; };
	using Products = std::vector<Product>;

	Products	products;
	if (_terms.size() == 0)
		os << "0";
	else
	{
		for (auto it = _terms.begin(); it != _terms.end(); it++)
		{
			if (it->second)
				products.push_back(Product { it->second, "x" + std::to_string(it->first) });
		}

		if (!products.empty()) {
			os << products[0].value << products[0].suffix;
			for (auto it = products.begin() + 1; it != products.end(); it++)
			{
				if (it->value >= 0)
					os << " + " << it->value << it->suffix;
				else
					os << " - " << -it->value << it->suffix;

			}
		}
		else
			os << "0";
	}
}

std::ostream	&operator<<(std::ostream &o, Polynom const &rhs)
{
	rhs.display(o);
	return o;
}