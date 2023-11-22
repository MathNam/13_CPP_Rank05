#ifndef	FORM_CLASS_H
# define FORM_CLASS_H

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {
public:
	Form(void);
	Form(Form const & src);
	Form(std::string const & name, int const gradeToSign, int const gradeToExecute);
	~Form(void);

	Form&	operator=(Form const & src);

	std::string const &	getName(void) const;
	bool				isSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;
	void	beSigned(Bureaucrat const & Bureaucrat);

private:
	class GradeTooLowException : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class GradeTooHighException : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	class AlreadySignedException : public std::exception {
		public:
			virtual const char*	what() const throw();
	};

	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_execGrade;
};

std::ostream&	operator<<(std::ostream& os, Form const & obj);

#endif