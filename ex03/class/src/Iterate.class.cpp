/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterate.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:27:26 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:22:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iterate.class.hpp"

static void executeQueue(std::queue <Instruction *> queue)
{
	while (!queue.empty())
	{
		queue.front()->execute();
		queue.pop();
	}
}

void Iterate::execute(void)
{
	while (*::memory_pointer)
		executeQueue(*_instruction_queue);
}

Iterate::~Iterate(void)
{
	while (!_instruction_queue->empty())
	{
		delete _instruction_queue->front();
		_instruction_queue->pop();
	}
	delete _instruction_queue;
}
