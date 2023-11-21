#ifndef	FORM_CLASS_H
# define FORM_CLASS_H

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm {
public:
	AForm(void);
	AForm(AForm const & src);
	AForm(std::string const & name, int const gradeToSign, int const gradeToExecute);
	virtual ~AForm(void);

	virtual AForm&	operator=(AForm const & rhs);
	std::string const &	getName(void) const;

	bool			isSigned(void) const;
	int				getSignGrade(void) const;
	int				getExecGrade(void) const;
	void			sign(Bureaucrat const & Bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

protected:
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

	class NotSigned : public std::exception {
		public:
			virtual const char* what() const throw();
	};
private:
	std::string const	_name;
	bool				_isSigned;
	int const			_signGrade;
	int const			_execGrade;
};

std::ostream&	operator<<(std::ostream& os, AForm const & obj);

#endif