#include "UI.hpp"
#include "Form.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test Form with correct values" + RESET);

		//Default constructor
		Form	Form1;
		assert(Form1.getName().empty());
		assert(Form1.getSigned() == false);
		assert(Form1.getGradeToSign() == GRADEMAX);
		assert(Form1.getGradeToExecute() == GRADEMAX);

		//Input constructor
		Form	Form2("paperwork", 75, 150);
		assert(Form2.getName() == "paperwork");
		assert(Form2.getSigned() == false);
		assert(Form2.getGradeToSign() == 75);
		assert(Form2.getGradeToExecute() == 150);

		//Copy constructor
		Form Form3(Form2);
		assert(Form3.getName() == Form2.getName());
		assert(Form3.getSigned() == false);
		assert(Form3.getGradeToSign() == Form2.getGradeToSign());
		assert(Form3.getGradeToExecute() == Form2.getGradeToExecute());

		//Copy assingment operator
		Form Form4("Bonjour", 123, 123);
		Form4 = Form1;
		assert(Form4.getName() == "Bonjour");
		assert(Form4.getSigned() == false);
		assert(Form4.getGradeToSign() == 123);
		assert(Form4.getGradeToExecute() == 123);
	}

	UI::printLine("\n");
	{
		UI::printLine(RED + "Test Form with incorrect grade values" + RESET);
		try {
			Form	Form1("test", 0, 1);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}

	UI::printLine("\n");
	{
		UI::printLine(RED + "Test Form with incorrect grade values" + RESET);
		try {
			Form	Form1("test", 1, 151);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}

	// UI::printLine("\n");

	// {
	// 	UI::printLine(RED + "Test Bureaucraat correct increment and decrement" + RESET);
		
	// 	Form	Form1("John", 75);
		
	// 	std::cout << Form1 << std::endl;
	// 	std::cout << ++Form1 << std::endl;
	// 	std::cout << Form1++ << std::endl;
	// 	std::cout << Form1 << std::endl;
	// 	std::cout << --Form1 << std::endl;
	// 	std::cout << Form1-- << std::endl;
	// 	std::cout << Form1 << std::endl;
	// }

	// UI::printLine("\n");

	// {
	// 	UI::printLine(RED + "Test Bureaucraat incorrect increment" + RESET);

	// 	try {
	// 		Form	Form1("John", 1);
	
	// 		std::cout << Form1 << std::endl;
	// 		std::cout << ++Form1 << std::endl;
	// 		std::cout << Form1 << std::endl;
	// 	}
	// 	catch (const std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }

	// UI::printLine("\n");

	// {
	// 	UI::printLine(RED + "Test Bureaucraat incorrect decrement" + RESET);

	// 	try {
	// 		Form	Form1("John", 150);
	
	// 		std::cout << Form1 << std::endl;
	// 		std::cout << --Form1 << std::endl;
	// 		std::cout << Form1 << std::endl;
	// 	}
	// 	catch (const std::exception & e) {
	// 		UI::printLine(e.what());
	// 	}
	// }
}

