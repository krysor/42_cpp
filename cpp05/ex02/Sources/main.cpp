#include "UI.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test ShrubberyCreationForm" + RESET);

		//Default constructor
		ShrubberyCreationForm	Form1;
		std::cout << Form1 << std::endl;

		assert(Form1.getName() == "ShrubberyCreationForm");
		assert(Form1.getSigned() == false);
		assert(Form1.getGradeToSign() == SCDEFAULTGRADETOSIGN);
		assert(Form1.getGradeToExecute() == SCDEFAULTGRADETOEXEC);
		assert(Form1.getTarget().empty());

		//Target constructor
		ShrubberyCreationForm	Form2("test");
		std::cout << Form2 << std::endl;
		assert(Form2.getName() == "ShrubberyCreationForm");
		assert(Form2.getSigned() == false);
		assert(Form2.getGradeToSign() == SCDEFAULTGRADETOSIGN);
		assert(Form2.getGradeToExecute() == SCDEFAULTGRADETOEXEC);
		assert(Form2.getTarget() == "test");

		//Copy constructor
		ShrubberyCreationForm Form3(Form2);
		std::cout << Form3 << std::endl;
		assert(Form3.getName() == Form2.getName());
		assert(Form3.getSigned() == Form2.getSigned());
		assert(Form3.getGradeToSign() == Form2.getGradeToSign());
		assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());
		assert(Form3.getTarget() == Form2.getTarget());

		//Copy assingment operator
		ShrubberyCreationForm Form4;
		Form4 = Form2;
		std::cout << Form4 << std::endl;
		assert(Form4.getName() == Form1.getName());
		assert(Form4.getSigned() == Form1.getSigned());
		assert(Form4.getGradeToSign() == Form1.getGradeToSign());
		assert(Form4.getGradeToExecute() == Form1.getGradeToExecute());
		assert(Form4.getTarget() == Form1.getTarget());
	}
	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test Form with incorrect grade values" + RESET);
	// 	try {
	// 		Form	Form1("test", 0, 1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test Form with incorrect grade values" + RESET);
	// 	try {
	// 		Form	Form1("test", 1, 151);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test beSigned with high enough value Bureaucrat" + RESET);
	// 	try {
	// 		Bureaucrat	bureaucrat1("Steve", 74);
	// 		Form		form1("test", 75, 75);
			
	// 		form1.beSigned(bureaucrat1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test beSigned with incorrect value Bureaucrat" + RESET);
	// 	try {
	// 		Bureaucrat	bureaucrat1("Steve", 75);
	// 		Form		form1("test", 74, 75);
			
	// 		form1.beSigned(bureaucrat1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test signForm with correct value" + RESET);
	// 	try {
	// 		Bureaucrat	bureaucrat1("Steve", 75);
	// 		Form		form1("test", 75, 75);
			
	// 		bureaucrat1.signForm(form1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test signForm with incorrect value" + RESET);
	// 	try {
	// 		Bureaucrat	bureaucrat1("Steve", 75);
	// 		Form		form1("test", 74, 75);
			
	// 		bureaucrat1.signForm(form1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");
	// {
	// 	UI::printLine(RED + "Test signForm with an already signed form" + RESET);
	// 	try {
	// 		Bureaucrat	bureaucrat1("Steve", 75);
	// 		Form		form1("test", 75, 75);
			
	// 		bureaucrat1.signForm(form1);
	// 		bureaucrat1.signForm(form1);
	// 	}
	// 	catch (std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }
}

