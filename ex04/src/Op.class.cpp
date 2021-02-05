/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Op.class.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 20:40:22 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 21:07:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Op.class.hpp>

static inline void add(int & a, int & b) { std::cout << "OP Add"; a += b; }
static inline void sub(int & a, int & b) { std::cout << "OP Substract"; a -= b; }
static inline void mul(int & a, int & b) { std::cout << "OP Multiply"; a *= b; }
static inline void div(int & a, int & b) { std::cout << "OP Divide"; a /= b; }

void Op::doOp(std::stack <int> & stack)
{
	std::map<char, void (*)(int &, int &)> op;
	op['+'] = &add;
	op['-'] = &sub;
	op['*'] = &mul;
	op['/'] = &div;
	int top;

	top = stack.top();
	stack.pop();
	(*op[_op])(stack.top(), top);
}
