/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:16:26 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/31 22:40:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <string>
#include <iostream>

int main(void)
{
	Span test(10);

	std::cout << "BASIC TEST" << std::endl << std::endl;
	try
	{
		test.addNumber(0);
		test.addNumber(25);
		test.addNumber(5);
		test.addNumber(50);
		test.addNumber(20);
		test.addNumber(11);
		test.addNumber(48);
		test.addNumber(42);
		test.addNumber(13);
		test.addNumber(130);
		test.addNumber(25);
		test.addNumber(25);
		test.addNumber(25);
		test.addNumber(25);
		test.addNumber(25);
	}
	catch (std::exception & e) { std::cout << e.what() << std::endl; }

	std::cout << "{ ";
	for (Span::Iterator it = test.begin(); (it + 1) != test.end(); it++)
		std::cout << *it << ", ";
	std::cout << *(test.end() - 1) << " }" << std::endl;
	std::cout << "shortestSpan " << test.shortestSpan() << std::endl;
	std::cout << "longestSpan " << test.longestSpan() << std::endl << std::endl;
	std::cout << "Press any key to continue" << std::endl;
	std::string dummy;
	std::getline(std::cin, dummy);
	std::cout << "10000 NUMBERS TEST" << std::endl << std::endl;

	Span big(10000);
	big.randomFill(0, INT_MAX);
	std::cout << "{ ";
	for (Span::Iterator it = big.begin(); it != big.begin() + 5; it++)
		std::cout << *it << ", ";
	std::cout << "[...], " << *(big.end() - 1) << " }" << std::endl;
	std::cout << "shortestSpan " << big.shortestSpan() << std::endl;
	std::cout << "longestSpan " << big.longestSpan() << std::endl;
	return (0);
}
