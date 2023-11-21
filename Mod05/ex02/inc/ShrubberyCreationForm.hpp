#ifndef	SHRUBBERY_FORM_H
# define SHRUBBERY_FORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <string>

class ShrubberyCreationForm : public AForm {
public:
	static int const	gradeToSign = 145;
	static int const	gradeToExecute = 137;

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & rhs);

	std::string const &	getTarget(void) const;
	void execute(Bureaucrat const & executor) const;

private:
	static std::string const	_treeOne;
	static std::string const	_treeTwo;
	std::string					_target;
};

std::ostream&	operator<<(std::ostream& os, ShrubberyCreationForm const & obj);

#endif