/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 22:43:02 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/31 23:31:42 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iterator>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

	MutantStack(void) : std::stack<T>() { }
	MutantStack(const MutantStack & src) : std::stack<T>(src) { }
	virtual ~MutantStack(void) { }

	T & operator[](const int idx) { return (c[idx]); }

	class iterator : public std::iterator <std::random_access_iterator_tag, int, std::ptrdiff_t, const int*, int&>
	{
		public:

		iterator(int * pointer) : _ptr(pointer) { }
		iterator(const iterator & src) : _ptr(src._ptr) { }

		int & operator*(void) const { return (*_ptr); }
		int * operator->(void) const { return (_ptr); }

		inline bool operator== (const iterator & b) { return (_ptr == b._ptr); };
		inline bool operator== (const int * b) { return (_ptr == b); };
		inline bool operator!= (const iterator & b) { return (_ptr != b._ptr); };
		inline bool operator!= (const int * b) { return (_ptr != b); };
		inline bool operator<= (const iterator & b) { return (_ptr <= b._ptr); };
		inline bool operator<= (const int * b) { return (_ptr <= b); };
		inline bool operator>= (const iterator & b) { return (_ptr >= b._ptr); };
		inline bool operator>= (const int * b) { return (_ptr >= b); };
		inline bool operator< (const iterator & b) { return (_ptr < b._ptr); };
		inline bool operator< (const int * b) { return (_ptr < b); };
		inline bool operator> (const iterator & b) { return (_ptr > b._ptr); };
		inline bool operator> (const int * b) { return (_ptr > b); };

		inline iterator & operator++(void) { _ptr++; return (*this); }
		inline iterator operator++(int) { iterator tmp = *this; ++(*this); return (tmp); }
		inline iterator & operator--(void) { _ptr--; return (*this); }
		inline iterator operator--(int) { iterator tmp = *this; --(*this); return (tmp); }
		inline iterator & operator+=(difference_type b) { this->_ptr += b; return (*this); }
		inline iterator & operator-=(difference_type b) { this->_ptr -= b; return (*this); }
		inline iterator operator+(difference_type b) const { return (iterator(_ptr + b)); }
		inline iterator operator-(difference_type b) const { return (iterator(_ptr - b)); }
		inline difference_type operator+(const iterator & b) const { return (reinterpret_cast<difference_type>(_ptr) + reinterpret_cast<difference_type>(b._ptr)); }
		inline difference_type operator-(const iterator & b) const { return (reinterpret_cast<difference_type>(_ptr) - reinterpret_cast<difference_type>(b._ptr)); }

		int * _ptr;
	};

	iterator begin() { return (iterator(&c[0])); }
	iterator end() { return (iterator(&c[c.size()])); }

	private:

	using std::stack<T>::c;
};

#endif
