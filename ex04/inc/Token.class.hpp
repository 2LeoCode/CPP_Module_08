/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:38:27 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 20:49:14 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <iostream>
# include <string>
# include <exception>

class Token
{
	public:

	virtual ~Token(void) { }
	virtual std::ostream & display(std::ostream & out) const = 0;

	struct UnknownCharacterException : public std::exception
	{
		UnknownCharacterException(char c) : _c(c) { }
		const char * what(void) const throw() { std::string out("Unknown Character `"); out += _c, out += '`'; return (out.c_str()); }
		char _c;
	};
};

inline std::ostream & operator<<(std::ostream & out, Token & t) { return (t.display(out)); }

# include "Num.class.hpp"
# include "Op.class.hpp"
# include "ParOpen.class.hpp"
# include "ParClose.class.hpp"

#endif
