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

const char* Intern::InvalidName::what(void) const throw()
{
	return ("Invalid form name.");
}

AForm*	createShubberyCreationForm(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	createRobotomyRequestForm(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm*	createPresidentialPardonForm(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string const & name, std::string const & target)
{
	if (name.empty())
		throw Intern::NameRequired();

	static std::string formList[3] = {"ShurubberyCreationForm",
							"RobotomyRequestForm",
							"PresidentialPardonForm"};
	AForm*	(*function_tab[3])(std::string const &) = {
				&createShubberyCreationForm,
				&createRobotomyRequestForm,
				&createPresidentialPardonForm
			};
	for (int i = 0; i < 3; i++){
		if (name == formList[i]){
			AForm* Form = (function_tab[i])(target);
			return Form;
		}
	}
	throw Intern::InvalidName();
}
