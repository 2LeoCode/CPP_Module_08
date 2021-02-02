/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:35:51 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:28:15 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Mindopen.hpp>

int main(int argc, char **argv)
{
	try {
	while (--argc)
	{
		std::ifstream in(argv[argc], std::ios::in);
		std::string fileContent, tmp;

		std::cout << argv[argc] << std::endl;
		if (in.fail())
			throw (std::runtime_error("Failed to open file"));
		while (std::getline(in, tmp))
			fileContent += tmp;
		mindopen(fileContent);
		std::cout << std::endl << std::endl;
	} } catch (std::exception & e) { std::cout << e.what() << std::endl; }
	return (0);
}
