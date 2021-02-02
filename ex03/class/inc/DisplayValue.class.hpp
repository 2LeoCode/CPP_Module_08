/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayValue.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:50 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:08:36 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAYVALUE_HPP
# define DISPLAYVALUE_HPP

# include <Instruction.class.hpp>

class DisplayValue : public Instruction
{
	public:

	DisplayValue(void) : Instruction() { }
	virtual ~DisplayValue(void) { }

	void execute (void) { std::cout << *::memory_pointer; }
};


#endif
