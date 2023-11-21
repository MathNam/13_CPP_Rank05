#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const & cpy)
{
	(void)cpy;
	std::cout << "Intern copy constructor called." << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
}

Intern& Intern::operator=(Intern const & rhs)
{
	std::cout << "Intern assignment operator overload called." << std::endl;
	(void)rhs;
	return(*this);
}

const char* Intern::NameRequired::what(void) const throw()
{
	return ("Form name required.");
}

const char* Intern::NameRequired::what(void) const throw()
{
	return ("Invalid form name.");
}

AForm*	Intern::makeForm(std::string const & name, std::string const & target)
{
	if (!name)
		throw Intern::NameRequired();

	static std::string formList[3] = {"ShurubberyCreationForm",
							"RobotomyRequestForm",
							"PresidentialPardonForm"};
	AFrom*	(Intern::*function_tab[3])(std::string const & target) = {
				&Intern::createShubberyCreationForm,
				&Intern::createRobotomyRequestForm,
				&Intern::createPresidentialPardonForm
			};
	for (i = 0; i < 3; i++){
		if (name == formList[i]){
			AForm* Form = (this->function_tab[i])(name);
			return Form;
		}
	}
	throw 	
}
