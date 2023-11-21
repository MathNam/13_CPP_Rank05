#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), _target("Unknown")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	AForm("Presidential pardon Form", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), _target(target)
{
	std::cout << "PresidentialPardonForm target constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	std::cout << "PresidentialPardonForm assignment operator overload called." << std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
	return ;
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw(AForm::NotSigned());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());

	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::ostream&	operator<<(std::ostream & os, PresidentialPardonForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getSignGrade()
		<< "; to execute: " << obj.getExecGrade() << ")";
	return (os);
}
