#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

AForm::AForm(void) :	_name("Basic AForm"),
					_isSigned(false),
					_signGrade(Bureaucrat::lowestGrade),
					_execGrade(Bureaucrat::lowestGrade)
{
	std::cout << "AForm default constructor called." << std::endl;
	return ;
}

AForm::AForm(AForm const & src) :	_name(src._name),
								_isSigned(false),
								_signGrade(src._signGrade),
								_execGrade(src._execGrade)
{
	std::cout << "AForm copy constructor called." << std::endl;
	return ;
}

AForm::AForm(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_signGrade(gradeToSign),
				_execGrade(gradeToExecute)
{
	std::cout << "AForm attribute constructor called." << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade )
		throw (AForm::GradeTooHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
	return ;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called." << std::endl;
	return ;
}

AForm&	AForm::operator=(AForm const & rhs)
{
	std::cout << "AForm assignment operator overload called." << std::endl;
	if (this != &rhs) {
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
	return ;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high.");
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low.");
}

const char*	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

const char*	AForm::NotSigned::what(void) const throw()
{
	return ("Form must be signed to be executed.");
};

std::ostream&	operator<<(std::ostream & os, AForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getSignGrade()
		<< "; to execute: " << obj.getExecGrade() << ")";
	return (os);
}