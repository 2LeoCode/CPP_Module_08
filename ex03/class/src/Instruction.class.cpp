/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:27:36 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:15:19 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Instruction.class.hpp"

char memory_buffer[MINDOPEN_MEMORY_BUF] = { 0 };
char * memory_pointer = memory_buffer;

void Instruction::resetMemoryBuffer(void)
{
	for (int i = 0; i < MINDOPEN_MEMORY_BUF; i++)
		::memory_buffer[i] = 0;
	::memory_pointer = ::memory_buffer;
}
