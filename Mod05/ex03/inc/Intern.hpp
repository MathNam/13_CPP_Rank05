#ifndef INTERN_H
# define INTERN_H

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include <string>

class Intern {
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern&	operator=(Intern const & rhs);
	AForm*	makeForm(std::string const & name, std::string const & target);

private:
	class NameRequired : public std::exception {
		virtual const char* what(void) const throw();
	};
	class InvalidName : public std::exception {
		virtual const char* what(void) const throw();
	};
	AForm* createShubberyCreationForm(std::string const & target);
	AForm* createRobotomyRequestForm(std::string const & target);
	AForm* createPresidentialPardonForm(std::string const & target);
};

#endif