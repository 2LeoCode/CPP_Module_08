/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Num.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:43:23 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 20:55:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_HPP
# define NUM_HPP

# include "Token.class.hpp"

class Num : public Token
{
	public:

	Num(int n) : _n(n) { }
	virtual ~Num(void) { }

	virtual inline std::ostream & display(std::ostream & out) const { out << "Num(" << _n << ')'; return (out); }
	virtual inline int number(void) const { return (_n); }

	private:

	int _n;
};

#endif
