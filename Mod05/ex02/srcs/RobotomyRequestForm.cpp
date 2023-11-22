#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy request Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), _target("Unknown")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	AForm("Robotomy request Form", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), _target(target)
{
	std::cout << "RobotomyRequestForm target constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	std::cout << "RobotomyRequestForm assignment operator overload called." << std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
	return ;
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw(AForm::NotSigned());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << "'s robotomy has failed." << std::endl;
}

std::ostream&	operator<<(std::ostream & os, RobotomyRequestForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getSignGrade()
		<< "; to execute: " << obj.getExecGrade() << ")";
	return (os);
}
