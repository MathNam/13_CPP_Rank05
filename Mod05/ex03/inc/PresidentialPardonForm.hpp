#ifndef	PRESIDENTIAL_FORM_H
# define PRESIDENTIAL_FORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm {
public:
	static int const	gradeToSign = 25;
	static int const	gradeToExecute = 5;

	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string const & target);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	~PresidentialPardonForm(void);

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs);

	std::string const &	getTarget(void) const;
	void execute(Bureaucrat const & executor) const;

private:
	std::string					_target;
};

std::ostream&	operator<<(std::ostream& os, PresidentialPardonForm const & obj);

#endif