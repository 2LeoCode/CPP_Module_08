/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 22:58:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/30 16:51:10 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <exception>
# include <map>
# include <unordered_map>
# include <cstring>

struct NotFoundException : public std::exception
{
	const char * what(void) const throw() { return ("not_found_exception"); }
};

template <class Identifier> int & easyfind(const std::map<Identifier, int> map, int n)
{
	for (typename std::map<Identifier, int>::const_iterator it = map.begin(); it != map.end(); it++)
		if (it->second == n)
			return (const_cast<int &>(it->second));
	throw (NotFoundException());
}

template <class Identifier> int & easyfind(const std::multimap<Identifier, int> map, int n)
{
	for (typename std::multimap<Identifier, int>::const_iterator it = map.begin(); it != map.end(); it++)
		if (it->second == n)
			return (const_cast<int &>(it->second));
	throw (NotFoundException());
}

template <class T> int & easyfind(const T container, int n)
{
	typename T::const_iterator i = std::find(container.begin(), container.end(), n);
	if (i != container.end())
		return (const_cast<int &>(*i));
	throw (NotFoundException());
}

#endif
