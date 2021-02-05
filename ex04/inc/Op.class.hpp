/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Op.class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:53:13 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 21:03:20 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_HPP
# define OP_HPP

# include "Token.class.hpp"
# include <iostream>
# include <stack>
# include <map>

class Op : public Token
{
	public:

	Op(char c) : _op(c) { if (std::string("+-*/").find(c) == std::string::npos) throw (UnknownCharacterException(c)); }
	virtual ~Op(void) { }

	virtual inline std::ostream & display(std::ostream & out) const { out << "Op(" << _op << ')'; return (out); }
	inline char getOp(void) const { return (_op); }
	void doOp(std::stack<int> &);

	private:

	char _op;
};

#endif
