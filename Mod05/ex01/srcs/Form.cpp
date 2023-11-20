#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

Form::Form(void) :	_name("Basic Form"),
					_isSigned(false),
					_gradeRequiredToSign(Bureaucrat::lowestGrade),
					_gradeRequiredToExecute(Bureaucrat::lowestGrade)
{
	std::cout << "Form default constructor called." << std::endl;
	return ;
}

Form::Form(Form const & src) :	_name(src._name),
								_isSigned(false),
								_gradeRequiredToSign(src._gradeRequiredToSign),
								_gradeRequiredToExecute(src._gradeRequiredToExecute)
{
	std::cout << "Form copy constructor called." << std::endl;
	return ;
}

Form::Form(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_gradeRequiredToSign(gradeToSign),
				_gradeRequiredToExecute(gradeToExecute)
{
	std::cout << "Form attribute constructor called." << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade )
		throw (Form::GradeTooHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());
	return ;
}

Form::~Form(void)
{
	std::cout << "Form destructor called." << std::endl;
	return ;
}

Form &	Form::operator=(Form const & src)
{
	std::cout << "Form assignment operator overload called." << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::isSigned(void) const
{
	return (this->_isSigned);
}

int	Form::getGradeRequiredToSign(void) const
{
	return (this->_gradeRequiredToSign);
}

int	Form::getGradeRequiredToExecute(void) const
{
	return (this->_gradeRequiredToExecute);
}

void	Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiredToSign)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
	return ;
}

const char *	Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	Form::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

std::ostream &	operator<<(std::ostream & os, Form const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getGradeRequiredToSign()
		<< "; to execute: " << obj.getGradeRequiredToExecute() << ")";
	return (os);
}