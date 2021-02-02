/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetValue.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:22:42 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:08:23 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GetValue.class.hpp"

void GetValue::execute(void)
{
	std::string s;
	while (s.length() != 1)
		std::getline(std::cin, s);
	*::memory_pointer = *s.begin();
}
