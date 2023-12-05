/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:50:38 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/05 13:52:32 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_POLISH_NOTATION_HPP
#define REVERSE_POLISH_NOTATION_HPP

#include "Colors.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
public:
	std::stack<int> _stack;
	int calculate( void );

private:
	class EndOfInputException : public std::exception {
		public:
			virtual const char * what( void ) const throw();
	};

	RPN(void);
	RPN & operator=( RPN & src );
	RPN(RPN&	src);
	~RPN();

	_checkStack();
};

#endif
