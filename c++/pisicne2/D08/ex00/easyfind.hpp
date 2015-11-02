/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenoud- <lrenoud-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 14:36:28 by lrenoud-          #+#    #+#             */
/*   Updated: 2015/04/17 20:29:32 by lrenoud-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iostream>
#include <list>

template<typename T>
typename T::const_iterator	easyfind(T const &list, int i)
{
	return std::find(list.begin(), list.end(), i);
}

#endif // EASYFIND_HPP
