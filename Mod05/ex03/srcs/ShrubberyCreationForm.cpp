#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute), _target("Unknown")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("Shrubbery Creation Form", ShrubberyCreationForm::gradeToSign, ShrubberyCreationForm::gradeToExecute), _target(target)
{
	std::cout << "ShrubberyCreationForm target constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	std::cout << "ShrubberyCreationForm assignment operator overload called." << std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
	return ;
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned())
		throw(AForm::NotSigned());
	else if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());

	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc | std::ofstream::app);
	if (ofs.is_open())
	{
		if (std::rand() % 2)
			ofs << ShrubberyCreationForm::_treeOne;
		else
			ofs << ShrubberyCreationForm::_treeTwo;
		std::cout << "A shrubbery has been planted at "
				<< this->_target << "_shrubbery." << std::endl;
		ofs.close();
	}
	return ;
}

std::ostream&	operator<<(std::ostream & os, ShrubberyCreationForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Required grade to sign: " << obj.getSignGrade()
		<< "; to execute: " << obj.getExecGrade() << ")";
	return (os);
}

std::string const ShrubberyCreationForm::_treeOne =
"\n"
"                %%%,%%%%%%%\n"
"                 ,'%% \\\\-*%%%%%%%\n"
"           ;%%%%%*%   _%%%%\"\n"
"            ,%%%       \\(_.*%%%%.\n"
"            % *%%, ,%%%%*(    '\n"
"          %^     ,*%%% )\\|,%%*%,_\n"
"               *%    \\/ #).-\"*%%*\n"
"                   _.) ,/ *%,\n"
"           _________/)#(_____________\n\n";

std::string const	ShrubberyCreationForm::_treeTwo =
"\n"
"           \\/ |    |/\n"
"        \\/ / \\||/  /_/___/_\n"
"         \\/   |/ \\/\n"
"    _\\__\\_\\   |  /_____/_\n"
"           \\  | /          /\n"
"  __ _-----`  |{,-----------~\n"
"            \\ }{\n"
"             }{{\n"
"             }}{\n"
"             {{}\n"
"       , -=-~{ .-^- _\n"
"             `}\n"
"              {\n\n";