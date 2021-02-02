/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 23:18:02 by lsuardi           #+#    #+#             */
/*   Updated: 2021/01/30 01:03:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "easyfind.hpp"
# include <map>
# include <string>
# include <vector>
# include <string>
# include <iostream>

int main(void)
{
	std::vector<int> a;
	std::map<std::string, int> b;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	b["hello"] = 1;
	b["world"] = 2;
	b["foo"] = 3;
	b["bar"] = 4;

	try { int & ret = easyfind (b, 3); std::cout << ret << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { int & ret = easyfind (b, 5); std::cout << ret << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { int & ret = easyfind (a, 3); std::cout << ret << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	try { int & ret = easyfind (a, 5); std::cout << ret << std::endl; }
	catch (std::exception & e) { std::cout << e.what() << std::endl; }
	return (0);
}
