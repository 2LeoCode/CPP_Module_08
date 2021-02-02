/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IncrementValue.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:44 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:08:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCREMENTVALUE_HPP
# define INCREMENTVALUE_HPP

# include <Instruction.class.hpp>

class IncrementValue : public Instruction
{
	public:

	IncrementValue(void) : Instruction() { }
	virtual ~IncrementValue(void) { }

	inline void execute (void) { ++(*::memory_pointer); }
};


#endif
