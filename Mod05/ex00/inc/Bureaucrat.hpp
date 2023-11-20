#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <string>

class Bureaucrat {
public:
	static int const	highestGrade = 1;
	static int const	lowestGrade = 150;

	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	Bureaucrat(std::string const & name, int grade);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const & src);

	std::string const &	getName(void) const;
	int					getGrade(void) const;

	void	incrementGrade(void);
	void	incrementGrade(int i);
	void	decrementGrade(void);
	void	decrementGrade(int i);

private:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			virtual const char*	what(void) const throw();
	};

	std::string const	_name;
	int					_grade;

};

std::ostream &	operator<<(std::ostream& os, Bureaucrat const & obj);

#endif