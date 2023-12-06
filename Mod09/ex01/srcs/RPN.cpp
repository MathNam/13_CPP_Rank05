/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:49:05 by mcombeau          #+#    #+#             */
/*   Updated: 2023/12/06 14:16:12 by maaliber         ###   ########.fr       */
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
	if (allowedChar.find(str) == std::string::npos)
		return false;
	return true;
}

static bool isOperator(std::string & str)
{
	if (str.length() != 1)
		return false;
	std::string	allowedChar = "+-*/";
	if (allowedChar.find(str) == std::string::npos)
		return false;
	return true;
}

static int	singleOp(std::string & operation, int x, int y)
{
	int res = 0;
	switch (operation[0]) {
		case '+':
			res = x + y;
			break;
		case '-':
			res = x - y;
			break;
		case '*':
			res = x * y;
			break;
		case '/':
			if ( y == 0 )
				throw (std::runtime_error("Division by 0"));
			res = x / y;
			break;
		default:
			throw (std::runtime_error(""));
	}
	return (res);
}


/*Private*/

void	RPN::addToStack(std::string & token)
{
	char* pEnd;
	
	int n = std::strtol(token.c_str(), &pEnd, 10);
	_stack.push(n);
}

void	RPN::operation(std::string & token)
{
	if (_stack.size() < 2)
		throw (std::runtime_error( "invalid input: invalid sequence, missing operands for operator" ));
	int y = _stack.top();
	_stack.pop();
	int x = _stack.top();
	_stack.pop();
	int res = singleOp(token, x, y);
	_stack.push(res);
}

/*Public*/

int RPN::calculate(std::string & input)
{
	std::stringstream ss(input);
	std::string	token;

	while (1) {
		ss >> token;
		if (isOperator(token))
			operation(token);
		else if(isOperand(token))
			addToStack(token);
		else
			throw (std::runtime_error("invalid character in input."));
		if (ss.eof()) {
			if (_stack.size() > 1)
				throw (std::runtime_error("invalid input: missing operators for operands."));
			if (_stack.size() == 0)
				throw (std::runtime_error("invalid input: missing operands for operator."));
			return (_stack.top());
		}	
	}
}
