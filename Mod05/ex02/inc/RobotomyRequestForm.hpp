#ifndef	ROBOTOMY_FORM_H
# define ROBOTOMY_FORM_H

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include <string>

class RobotomyRequestForm : public AForm {
public:
	static int const	gradeToSign = 72;
	static int const	gradeToExecute = 45;

	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm&	operator=(RobotomyRequestForm const & rhs);

	std::string const &	getTarget(void) const;
	void execute(Bureaucrat const & executor) const;

private:
	std::string					_target;
};

std::ostream&	operator<<(std::ostream& os, RobotomyRequestForm const & obj);

#endif