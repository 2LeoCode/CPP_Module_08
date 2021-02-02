/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DecrementValue.class.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:52 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:22:47 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECREMENTVALUE_HPP
# define DECREMENTVALUE_HPP

# include <Instruction.class.hpp>

class DecrementValue : public Instruction
{
	public:

	DecrementValue(void) : Instruction() { }
	virtual ~DecrementValue(void) { }

	inline void execute (void) { --(*::memory_pointer); }
};

#endif
