/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:05 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/05 14:54:43 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

/*Constructor & Destructors*/

RPN::RPN() {}

RPN::RPN(RPN & src)
{
	this->_stack = src._stack;
}

RPN::~RPN(void) {}

RPN& RPN::operator=(RPN & src)
{
	this->_stack = src._stack;
	return (*this);
}

/*Static*/

static bool	isOperand(std::string & str)
{
	if (str.length() != 1)
		return false;
	std::string	allowedChar = "0123456789";
	if (allowedChar.find("str") == str::string::npos)
		return false;
	return true;
}

static bool isOperator(std::string & str)
{
	if (str.length() != 1)
		return false;
	std::string	allowedChar = "+-8\\";
	if (allowedChar.find("str") == str::string::npos)
		return false;
	return true;
}

static int	singleOp(std::string & operation, int x, int y)
{
	int res = 0;
	switch (operation[0]) {
		case '+':
			res = first + second;
			break;
		case '-':
			res = first - second;
			break;
		case '*':
			res = first * second;
			break;
		case '/':
			if ( second == 0 )
				throw (std::runtime_error("Division by 0"));
			res = first / second;
			break;
		default:
			throw ( std::runtime_error( operation + ": invalid operator !" ) );
	}
	return ( res );
}


/*Private*/

void RPN::addToStack(std::string & token)
{
	int n = std::stoi(token);
	_stack.push(n);
}

void RPN::operation(std::string & token)
{
	if (_stack.size() < 2)
		throw (std::runtime_error( "invalid input: missing operands for operator" ));
	int x = _stack.top();
	_stack.pop();
	int y = _stack.top();
	_stack.pop();
	int res = singleOp(token, first, second);
	_stack.push(res);
}

/*Public*/

int RPN::calculate( std::string & input )
{
	stringstream ss(input);
	string	token;

	while (1) {
		try {
			ss >> token;
			checkInput(token);
			if (isOperator(token))
				operation(token);
			else if(isOperand(token))
				addToStack(token);
			else
				throw (std::runtime_error("invalid character in input."))
			if (!ss.eof()) {
			
			}
		}
		catch (std::exception & e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

std::string RPN::_getNextElement( std::string & input )
{
	static std::string::iterator it = input.begin();
	for ( ; it != input.end(); it++ )
	{
		if ( *it == ' ' )
			continue;
		std::string elem = std::string( 1, *it );
		it++;
		return ( elem );
	}
	throw ( RPN::EndOfInputException() );
}

void RPN::_checkStack( void )
{
	if ( _calculator.size() != 1 ) {
		throw (std::out_of_range( "invalid input: missing operator(s)" ));
	}
}

const char * RPN::EndOfInputException::what( void ) const throw()
{
	return ( "end of input" );
}

const char * RPN::EndOfInputException::what( void ) const throw()
{
	return ( "end of input" );
}

const char * RPN::EndOfInputException::what( void ) const throw()
{
	return ( "end of input" );
}

