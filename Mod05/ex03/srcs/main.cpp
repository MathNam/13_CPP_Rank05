/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaliber <maaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:03:10 by mcombeau          #+#    #+#             */
/*   Updated: 2023/11/22 11:03:13 by maaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void	testInternFormCreation(std::string formName, std::string target)
{
	std::cout << std::endl << "---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	lowlyIntern = Intern();
	Bureaucrat bigBoss("Big Boss Barry", 1);
	AForm *	form;
	try {
		form = lowlyIntern.makeForm(formName, target);
		bigBoss.signForm(*form);
		bigBoss.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	srand(time(0));
	std::string const	shrubberyFormName = "Shrubbery Creation";
	std::string const	robotomyFormName = "Robotomy Request";
	std::string const	presidentialFormName = "Presidential Pardon";

	testInternFormCreation(shrubberyFormName, "Garden");
	testInternFormCreation(robotomyFormName, "Unsuspecting Customer");
	testInternFormCreation(presidentialFormName, "Jesus");
	testInternFormCreation("Bad Form Name", "Mr. X");
	testInternFormCreation("", "");	
	return (0);
}