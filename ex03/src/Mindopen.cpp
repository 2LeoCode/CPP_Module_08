/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mindOpen.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 19:54:53 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:57:32 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <Mindopen.hpp>

typedef Instruction * (*instructionConstructor)(void);

static inline Instruction * newIncrementPointer(void) { return (new IncrementPointer()); }
static inline Instruction * newDecrementPointer(void) { return (new DecrementPointer()); }
static inline Instruction * newIncrementValue(void) { return (new IncrementValue()); }
static inline Instruction * newDecrementValue(void) { return (new DecrementValue()); }
static inline Instruction * newDisplayValue(void) { return (new DisplayValue()); }
static inline Instruction * newGetValue(void) { return (new GetValue()); }

static std::queue<Instruction *> * getInstructionQueue(std::string & code, std::string::iterator begin_iter)
{
	std::queue<Instruction *> * queue = new std::queue<Instruction *>;
	std::map<char, instructionConstructor> map;
	
	map[MINDOPEN_INCREMENT_POINTER] = &newIncrementPointer;
	map[MINDOPEN_DECREMENT_POINTER] = &newDecrementPointer;
	map[MINDOPEN_INCREMENT_VALUE] = &newIncrementValue;
	map[MINDOPEN_DECREMENT_VALUE] = &newDecrementValue;
	map[MINDOPEN_DISPLAY_VALUE] = &newDisplayValue;
	map[MINDOPEN_GET_VALUE] = &newGetValue;

	for (std::string::iterator it = begin_iter; it != code.end(); it++)
	{
		if (*it == MINDOPEN_ITER_END)
		{
			if (begin_iter == code.begin())
				throw (std::runtime_error("InvalidMindopenSequence"));
			else
				return (queue);
		}
		else if (*it == MINDOPEN_ITER_BEGIN)
		{
			std::queue<Instruction *> * iterQueue = getInstructionQueue(code, it + 1);
			queue->push(new Iterate(iterQueue));
			it++;
			for (int count = 1; count; it++)
				if (it == code.end())
					throw (std::runtime_error("InvalidMindopenSequence(Missing Brackets)"));
				else if (*it == MINDOPEN_ITER_BEGIN)
					count++;
				else if (*it == MINDOPEN_ITER_END)
					count--;
			it--;
		}
		else if (std::string(MINDOPEN_CHARSET).find(*it) != std::string::npos)
			queue->push((*map[*it])());
	}
	return (queue);
}

void mindopen(std::string code)
{
	std::queue<Instruction *> * _instruction_queue = getInstructionQueue(code, code.begin());
	
	while (!_instruction_queue->empty())
	{
		_instruction_queue->front()->execute();
		delete _instruction_queue->front();
		_instruction_queue->pop();
	}
	delete _instruction_queue;
	Instruction::resetMemoryBuffer();
}
