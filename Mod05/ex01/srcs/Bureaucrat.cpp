#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void)
		: _name("John Doe"), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat default constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
		: _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Bureaucrat name/grade constructor called." << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called." << std::endl;
	return ;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & src)
{
	std::cout << "Bureaucrat assignment operator overload called." << std::endl;
	this->_grade = src._grade;
	return (*this);
}

std::string const &	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	this->incrementGrade(1);
}

void	Bureaucrat::incrementGrade(int i)
{
	if (this->_grade - i < Bureaucrat::highestGrade)
		return (throw(Bureaucrat::GradeTooHighException()));
	else {
		std::cout << *this << " was promoted to grade "
			<< this->_grade - i << "!" << std::endl;
		this->_grade -= i;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	this->decrementGrade(1);
}

void	Bureaucrat::decrementGrade(int i)
{
	if (this->_grade + i > Bureaucrat::lowestGrade)
		return (throw(Bureaucrat::GradeTooLowException()));
	else {
		std::cout << *this << " was demoted to grade "
			<< this->_grade + i << "!" << std::endl;
		this->_grade += i;
	}
	return ;
}

void	Bureaucrat::signForm(Form& form) const
{
	try {
		form.sign(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (std::exception const & e) {
		std::cout << *this << " couldn't sign " << form << " because: "
			<< e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too low.");	
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too high.");
}

std::ostream&	operator<<(std::ostream & os, Bureaucrat const & obj)
{
	os << "Bureaucrat \"" << obj.getName()
		<< "\" (grade: " << obj.getGrade() << ")";
	return (os);
}
