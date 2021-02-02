/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:41 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:14:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <iostream>
# include <queue>

# define MINDOPEN_MEMORY_BUF 9999

extern char memory_buffer[MINDOPEN_MEMORY_BUF];
extern char * memory_pointer;

class Instruction
{
	public:

	Instruction(void) { }
	virtual ~Instruction(void) { }

	virtual void execute(void) = 0;

	static void resetMemoryBuffer(void);
};

# include <IncrementPointer.class.hpp>
# include <DecrementPointer.class.hpp>
# include <IncrementValue.class.hpp>
# include <DecrementValue.class.hpp>
# include <DisplayValue.class.hpp>
# include <GetValue.class.hpp>
# include <Iterate.class.hpp>

#endif
