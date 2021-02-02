/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:16:01 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/31 22:22:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const Span & src) : _size(src._size), _size_max(src._size_max)
{
	_array = new int[_size_max];

	for (Iterator it = begin(), s_it = const_cast<Span&>(src).begin(); it != end(); it++, s_it++)
		*it = *s_it;
}

int & Span::operator[](uint32_t idx)
{
	if (idx >= _size)
		throw (std::runtime_error("out_of_range"));
	return (_array[idx]);
}

void Span::sort(void)
{
	for (Iterator it = begin(); it != end(); it++)
		for (Iterator it2 = it + 1; it2 != end(); it2++)
			if (*it2 < *it)
				utils::swap(*it2, *it);
}

void Span::randomFill(int a, int b)
{
	_size = _size_max;
	for (Iterator it = begin(); it != end(); it++)
		*it = utils::random(a, b);
}

void Span::addNumber(int n)
{
	if (_size >= _size_max)
		throw (std::runtime_error("container_is_full"));
	_array[_size++] = n;
}

uint32_t Span::longestSpan(void)
{
	if (_size < 2)
		throw (std::runtime_error("not_enough_elements"));
	std::pair <Span::Iterator, Span::Iterator> val = std::minmax_element(begin(), end());
	return (*val.second - *val.first);
}

uint32_t Span::shortestSpan(void)
{
	if (_size < 2)
		throw (std::runtime_error("not_enough_elements"));

	uint32_t span = longestSpan();
	Span s(*this);

	s.sort();
	for (Iterator it = s.begin(); (it + 1) != s.end(); it++)
		if (static_cast<uint32_t>(*(it + 1) - *it) < span)
			if (!(span = static_cast<uint32_t>(*(it + 1) - *it)))
				break ;
	return (span);
}
