/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParClose.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:41:08 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 19:36:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARCLOSE_HPP
# define PARCLOSE_HPP

# include "Token.class.hpp"

class ParClose : public Token
{
	public:

	ParClose(void) { }
	virtual ~ParClose(void) { }

	virtual inline std::ostream & display(std::ostream & out) const { out << "ParClose"; return (out); }
};

#endif
