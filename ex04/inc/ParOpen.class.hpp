/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParOpen.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 18:42:40 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/05 19:36:03 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAROPEN_HPP
# define PAROPEN_HPP

# include "Token.class.hpp"

class ParOpen : public Token
{
	public:

	ParOpen(void) { }
	virtual ~ParOpen(void) { }

	virtual std::ostream & display(std::ostream & out) const { out << "ParOpen"; return (out); }
};

#endif
