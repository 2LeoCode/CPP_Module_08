/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementPointer.class.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:45 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:08:50 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENTPOINTER_HPP
# define INCREMENTPOINTER_HPP

# include <Instruction.class.hpp>

class IncrementPointer : public Instruction
{
	public:

	IncrementPointer(void) : Instruction() { }
	virtual ~IncrementPointer(void) { }

	inline void execute (void) { ::memory_pointer++; }
};

#endif
