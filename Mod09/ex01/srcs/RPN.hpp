/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:50:38 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/06 10:25:14 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_POLISH_NOTATION_HPP
#define REVERSE_POLISH_NOTATION_HPP

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
	RPN(void);
	RPN & operator=( RPN & src );
	RPN(RPN& src);
	~RPN();

	int	calculate(std::string & input);

private:
	class EndOfInputException : public std::exception {
		public:
			virtual const char * what( void ) const throw();
	};
	
	std::stack<int> _stack;

	void	addToStack(std::string & token);
	void	operation(std::string & token);
};

#endif
