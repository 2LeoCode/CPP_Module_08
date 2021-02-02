/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetValue.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:52:48 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 19:56:39 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETVALUE_HPP
# define GETVALUE_HPP

# include <Instruction.class.hpp>

class GetValue : public Instruction
{
	public:

	GetValue(void) : Instruction() { }
	virtual ~GetValue(void) { }

	void execute (void);
};

#endif
