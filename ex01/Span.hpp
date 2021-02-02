/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 01:16:04 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/31 22:36:32 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iterator>
# include <cstddef>
# include <exception>
# include <stdexcept>
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <istream>

typedef struct timespec Timespec;

class Span
{
	public:

	Span(uint32_t n = 0) : _array(new int[n]), _size_max(n), _size() { }
	Span(const Span & src);
	~Span(void) { delete [] _array; }

	int & operator[](uint32_t idx);
	class Iterator : public std::iterator <std::random_access_iterator_tag, int, std::ptrdiff_t, const int*, int&>
	{
		public:

		Iterator(int * pointer) : _ptr(pointer) { }
		Iterator(const Iterator & src) : _ptr(src._ptr) { }

		int & operator*(void) const { return (*_ptr); }
		int * operator->(void) const { return (_ptr); }

		inline bool operator== (const Iterator & b) { return (_ptr == b._ptr); };
		inline bool operator== (const int * b) { return (_ptr == b); };
		inline bool operator!= (const Iterator & b) { return (_ptr != b._ptr); };
		inline bool operator!= (const int * b) { return (_ptr != b); };
		inline bool operator<= (const Iterator & b) { return (_ptr <= b._ptr); };
		inline bool operator<= (const int * b) { return (_ptr <= b); };
		inline bool operator>= (const Iterator & b) { return (_ptr >= b._ptr); };
		inline bool operator>= (const int * b) { return (_ptr >= b); };
		inline bool operator< (const Iterator & b) { return (_ptr < b._ptr); };
		inline bool operator< (const int * b) { return (_ptr < b); };
		inline bool operator> (const Iterator & b) { return (_ptr > b._ptr); };
		inline bool operator> (const int * b) { return (_ptr > b); };

		inline Iterator & operator++(void) { _ptr++; return (*this); }
		inline Iterator operator++(int) { Iterator tmp = *this; ++(*this); return (tmp); }
		inline Iterator & operator--(void) { _ptr--; return (*this); }
		inline Iterator operator--(int) { Iterator tmp = *this; --(*this); return (tmp); }
		inline Iterator & operator+=(difference_type b) { this->_ptr += b; return (*this); }
		inline Iterator & operator-=(difference_type b) { this->_ptr -= b; return (*this); }
		inline Iterator operator+(difference_type b) const { return (Iterator(_ptr + b)); }
		inline Iterator operator-(difference_type b) const { return (Iterator(_ptr - b)); }
		inline difference_type operator+(const Iterator & b) const { return (reinterpret_cast<difference_type>(_ptr) + reinterpret_cast<difference_type>(b._ptr)); }
		inline difference_type operator-(const Iterator & b) const { return (reinterpret_cast<difference_type>(_ptr) - reinterpret_cast<difference_type>(b._ptr)); }

		int * _ptr;
	};

	uint32_t size(void) { return (_size); }
	uint32_t size_max(void) { return (_size_max); }

	Iterator begin(void) { return (Iterator(_array)); }
	Iterator end(void) { return (Iterator(&_array[_size])); }

	void addNumber(int);
	void randomFill(int, int);
	void sort(void);

	uint32_t shortestSpan(void);
	uint32_t longestSpan(void);


	private:

	int * _array;
	uint32_t _size_max;
	uint32_t _size;
};

namespace utils
{
	template <typename T> T random(T a, T b)
	{
		static bool init = false;
	
		if (!init)
		{
			init = true;
			Timespec currentTime;
			clock_gettime(CLOCK_REALTIME, &currentTime);
			std::srand(currentTime.tv_nsec);
		}
		return (a + rand() % (b - a + 1));
	}

	template <typename T> void swap(T & a, T & b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}

#endif
