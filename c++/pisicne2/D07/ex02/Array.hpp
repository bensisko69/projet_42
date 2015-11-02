/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 17:04:28 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/15 22:02:17 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
	public:
		Array(void): tab(0), n(0) 
		{ 
		}

		Array(unsigned n): tab(new T[n]()), n(n)
		{ 
		}

		Array(const Array &src): tab(new T[src.n]), n(src.n)
		{
			for(unsigned i = 0; i < src.n; i++)
				tab[i] = src.tab[i];
		}

		~Array(void)
		{
			delete [] tab;
		}

		Array &operator=(Array const &rhs)
		{
			delete [] tab;
			tab = new T[rhs.n];
			for(unsigned i = 0; i < rhs.n; i++)
				tab[i] = rhs.tab[i];
			n = rhs.n;
			return *this;

		}
		T	&operator[](unsigned i)
		{
			if (i >= n)
				throw std::out_of_range("Hors des limite du temps");
			return tab[i];
		}

		T	operator[](unsigned i) const
		{
			if (i >= n)
				throw std::out_of_range("Hors des limite du temps");
			return tab[i];
		}

		unsigned 	size(void) const
		{
			return n;
		}

	private:
		T 				*tab;
		unsigned 	n;
};

#endif