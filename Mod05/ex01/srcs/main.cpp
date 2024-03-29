#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void	createTestForm(std::string name, int gradeToSign, int gradeToExecute)
{
	std::cout << std::endl << "-- Creating form named \""
		<< name << "\" with grade to sign " << gradeToSign
		<< " and grade to execute " << gradeToExecute << ":" << std::endl;
	try
	{
		Form	form(name, gradeToSign, gradeToExecute);
		std::cout << form << " successfully created." << std::endl;
		return ;
	}
	catch(std::exception const & e) {
		std::cerr << "Exception: " << e.what()  << std::endl;
	}
}

int	main(void)
{
	std::cout << std::endl << "---- TEST FORM DEFAULT CONSTRUCTOR" << std::endl;
	{
		Form form;
		std::cout << "Default form is: " << form << std::endl;
	}
	
	std::cout << std::endl << "---- TEST FORM ATTRIBUTE CONSTRUCTOR" << std::endl;
	createTestForm("Simple Form", 42, 42);
	createTestForm("Signable/Executable Form", 150, 1);
	createTestForm("Unsignable Form", 151, 1);
	createTestForm("Unexecutable Form", 1, 0);
	createTestForm("Unexecutable Form", -10, 140);
	{
		std::cout << std::endl << "---- TEST FORM COPY CONSTRUCTOR" << std::endl;
		Form form("FormXYZ", 42, 42);
		std::cout << "Form is " << form << std::endl;
		Form formCopy(form);
		Form operatorForm = form;
		std::cout << "operatorForm copy is " << operatorForm << std::endl;
		std::cout << "Form copy is " << formCopy << std::endl;
	}
	{
		std::cout << std::endl << "---- TEST FORM ASSIGNMENT OPERATOR" << std::endl;
		Bureaucrat	bureaucrat("Richard", 42);
		Form form1("Form #1", Bureaucrat::lowestGrade, Bureaucrat::highestGrade);
		Form form2("Form #2", 42, 42);

		std::cout << "Two forms created:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		bureaucrat.signForm(form2);
		std::cout << "Form 2 signed:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
		
		form1 = form2;
		std::cout << "First form = second form:\n"
			"\t" << form1 << "\n"
			"\t" << form2 << std::endl;
	}
	{
		std::cout << std::endl << "---- TEST BUREAUCRAT FORM SIGNING" << std::endl;
		Bureaucrat	tiredBureaucrat("Tired Ted", 150);
		Bureaucrat	depressedBureaucrat("Depressed Dorothy", 42);
		Bureaucrat	bigBoss("Boss Ben", 1);

		Form	basicForm("Basic Form", 150, 150);
		Form	averageForm("Average Form", 42, 42);
		Form	topForm("Top-Secret Form", 1, 1);

		std::cout << std::endl << "Three bureaucrats created:\n"
			"\t" << tiredBureaucrat << "\n"
			"\t" << depressedBureaucrat << "\n"
			"\t" << bigBoss << std::endl;

		std::cout << std::endl << "Attempting to sign " << basicForm << ":" << std::endl;
		tiredBureaucrat.signForm(basicForm);
		depressedBureaucrat.signForm(basicForm);
		bigBoss.signForm(basicForm);
		std::cout << std::endl;

		std::cout << std::endl << "Attempting to sign " << averageForm << ":" << std::endl;
		tiredBureaucrat.signForm(averageForm);
		depressedBureaucrat.signForm(averageForm);
		bigBoss.signForm(averageForm);
		std::cout << std::endl;
	
		std::cout << std::endl << "Attempting to sign "	<< topForm << ":" << std::endl;
		tiredBureaucrat.signForm(topForm);
		depressedBureaucrat.signForm(topForm);
		bigBoss.signForm(topForm);
		std::cout << std::endl;
	}
	return (0);
}
