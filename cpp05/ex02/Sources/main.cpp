#include "UI.hpp"
#include "Form.hpp"

int main( void ) 
{
	// {
	// 	UI::printLine(RED + "Test Form with correct values" + RESET);

	// 	//Default constructor
	// 	Form	Form1;
	// 	std::cout << Form1 << std::endl;
	// 	assert(Form1.getName().empty());
	// 	assert(Form1.getSigned() == false);
	// 	assert(Form1.getGradeToSign() == GRADEMAX);
	// 	assert(Form1.getGradeToExecute() == GRADEMAX);

	// 	//Input constructor
	// 	Form	Form2("paperwork", 75, 150);
	// 	std::cout << Form2 << std::endl;
	// 	assert(Form2.getName() == "paperwork");
	// 	assert(Form2.getSigned() == false);
	// 	assert(Form2.getGradeToSign() == 75);
	// 	assert(Form2.getGradeToExecute() == 150);

	// 	//Copy constructor
	// 	Form Form3(Form2);
	// 	std::cout << Form3 << std::endl;
	// 	assert(Form3.getName() == Form2.getName());
	// 	assert(Form3.getSigned() == false);
	// 	assert(Form3.getGradeToSign() == Form2.getGradeToSign());
	// 	assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());

	// 	//Copy assingment operator
	// 	Form Form4("Bonjour", 123, 123);
	// 	Form4 = Form1;
	// 	std::cout << Form4 << std::endl;
	// 	assert(Form4.getName() == "Bonjour");
	// 	assert(Form4.getSigned() == false);
	// 	assert(Form4.getGradeToSign() == 123);
	// 	assert(Form4.getGradeToExecute() == 123);
	// }

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

