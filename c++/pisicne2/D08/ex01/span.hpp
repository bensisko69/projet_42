/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 17:32:58 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/17 15:31:47 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span{
	public:
		Span(unsigned int n);
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		~Span(void);
		void			addNumber(unsigned int nbr);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		Span(void);
		template<typename T>
		void			addNumber(T begin, T end)
		{
			if ((_lst.size() + std::distance(begin, end)) < _maxSize)
			{
				_lst.insert(_lst.end(), begin, end);
				std::sort(_lst.begin(), _lst.end());
			}
			else
				throw MaxSize();
		}
	class MaxSize: public std::exception{
		public:
			MaxSize(void);
			~MaxSize(void) throw();
			MaxSize(MaxSize const &rhs);
			virtual const char* what() const throw();
		private:
			MaxSize &operator=(MaxSize const &src);
	};
	private:
		std::vector<unsigned int>	_lst;
		unsigned int			_maxSize;
};

#endif // SPAN_HPP
