/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matnam <matnam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:31:59 by mcombeau          #+#    #+#             */
/*   Updated: 2023/11/20 13:27:18 by matnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		int					getGradeRequiredToSign(void) const;
		int					getGradeRequiredToExecute(void) const;

		void	beSigned(Bureaucrat const & Bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

		class AlreadySignedException : public std::exception {
			public:
				virtual const char*	what(void) const throw();
		};

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeRequiredToSign;
		int const			_gradeRequiredToExecute;
};

std::ostream&	operator<<(std::ostream& os, Form const & obj);

#endif