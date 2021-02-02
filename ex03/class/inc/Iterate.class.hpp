/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterate.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:32 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:08:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATE_HPP
# define ITERATE_HPP

# include <Instruction.class.hpp>

class Iterate : public Instruction
{
	public:

	Iterate(std::queue<Instruction *> * queue) : Instruction(), _instruction_queue(queue) { }
	virtual ~Iterate(void);

	void execute(void);

	private:

	std::queue<Instruction *> * _instruction_queue;
};

#endif
