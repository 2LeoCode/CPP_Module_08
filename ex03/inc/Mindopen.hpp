/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mindopen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:27:41 by lsuardi           #+#    #+#             */
/*   Updated: 2021/02/02 20:59:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINDOPEN_HPP
# define MINDOPEN_HPP

# define MINDOPEN_CHARSET "><+-.,[]"
# define MINDOPEN_INCREMENT_POINTER MINDOPEN_CHARSET[0]
# define MINDOPEN_DECREMENT_POINTER MINDOPEN_CHARSET[1]
# define MINDOPEN_INCREMENT_VALUE MINDOPEN_CHARSET[2]
# define MINDOPEN_DECREMENT_VALUE MINDOPEN_CHARSET[3]
# define MINDOPEN_DISPLAY_VALUE MINDOPEN_CHARSET[4]
# define MINDOPEN_GET_VALUE MINDOPEN_CHARSET[5]
# define MINDOPEN_ITER_BEGIN MINDOPEN_CHARSET[6]
# define MINDOPEN_ITER_END MINDOPEN_CHARSET[7]

# include <Instruction.class.hpp>
# include <fstream>
# include <exception>
# include <map>

void mindopen(std::string);

#endif
