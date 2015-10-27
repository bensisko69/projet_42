/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 21:25:21 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/06/01 17:51:14 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "Eq.hpp"
# include <boost/spirit/include/qi.hpp>
# include <boost/spirit/repository/include/qi_seek.hpp>
# include <boost/spirit/include/phoenix.hpp>
# include <map>
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using Terms = std::map<uint, double>;

template <typename It, typename Skipper>
class pPolynome : public qi::grammar<It, Equation(), Skipper>
{
	Terms	terms;
	bool	isNegative;
	struct Member {
		double value;
		uint exponent;
	};
	qi::rule<It, uint(), Skipper> exponent;
	qi::rule<It, Member(), Skipper> member;
	qi::rule<It, Polynom(), Skipper> poly;
	qi::rule<It, Equation(), Skipper> eq;

public:
	pPolynome(): pPolynome::base_type(eq), isNegative(false)
	{
		using boost::phoenix::bind;
		using boost::phoenix::construct;
		using boost::spirit::repository::qi::seek;

		exponent = 
				qi::char_("xX")[qi::_val = 1]
			>>  -(-qi::char_('^') >> qi::uint_[qi::_val = qi::_1])
			;

		auto setExponent = [](Member & member, auto maybeExponent) {
			if (maybeExponent)
				member.exponent = *maybeExponent;
			else
				member.exponent = 0;
		};

		auto setMember = [this](Member member){
			if (isNegative)
				member.value = -member.value;
			terms[member.exponent] += member.value;
		};

		auto buildPolynom = [this](void){
			Polynom poly(terms);
			terms.clear();
			isNegative = false;
			return poly;
		};
		auto setSign= [this](char sign){
			isNegative = (sign == '-');
		};

		auto setDefaultMember = [](Member & member, uint exponent) {
			member.value = 1;
			member.exponent = exponent;
		};

		member = 
				(
					qi::double_[bind(&Member::value, qi::_val) = qi::_1]
				>>  -qi::char_('*') 
				>>  (-exponent)[bind(setExponent, qi::_val, qi::_1)]
				) 
			| 	exponent[bind(setDefaultMember, qi::_val, qi::_1)]
			;
			
		poly = (
				member[bind(setMember, qi::_1)] 
				% qi::char_("+-")[bind(setSign, qi::_1)]
			)[qi::_val = bind(buildPolynom)];

		eq = (poly >> '=' >> poly)[qi::_val = construct<Equation>(qi::_1, qi::_2)];
	}

};

int		main(int ac, char **av)
{
	(void)ac;
	pPolynome<std::string::iterator, ascii::blank_type>	poly;
	Equation eq;
	std::string str(av[1]); 
	auto it = str.begin();
	bool r = qi::phrase_parse(
		it,
		str.end(),
		poly,
		ascii::blank,
		eq
		);
	if (it != str.end() || r == false)
		std::cout << "No" << std::endl;
	else
	{
		eq.solve();
		std::cout << std::endl;
	}
	return 1;
}

// * => 0 N
// + => 1 N
// - => 0 1
