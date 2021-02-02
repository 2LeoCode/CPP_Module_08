/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementPointer.class.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:55 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:11:34 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENTPOINTER_HPP
# define DECREMENTPOINTER_HPP

# include <Instruction.class.hpp>

class DecrementPointer : public Instruction
{
	public:

	DecrementPointer(void) : Instruction() { }
	virtual ~DecrementPointer(void) { }

	inline void execute (void) { ::memory_pointer--; }
};

#endif
