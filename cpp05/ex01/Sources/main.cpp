#include "UI.hpp"
#include "Form.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test  with correct values" + RESET);

		//Default constructor
		Form	Form1;
		assert(Form1.getName().empty());
		assert(Form1.getGrade() == 150);

		//Name constructor
		Form	Form2("Gwenda");
		assert(Form2.getName() == "Gwenda");
		assert(Form2.getGrade() == 150);

		Form	Form3("");
		assert(Form3.getName() == "");

		//Grade constructor
		Form	Form4(1);
		assert(Form4.getGrade() == 1);

		Form	Form5(150);
		assert(Form5.getGrade() == 150);

		//Name grade constructor
		Form	Form6("Stephan", 75);
		assert(Form6.getName() == "Stephan");
		assert(Form6.getGrade() == 75);

		//Grade name constructor
		Form	Form7(1, "Xavier");
		assert(Form7.getName() == "Xavier");
		assert(Form7.getGrade() == 1);

		//Copy constructor
		Form Form8(Form7);
		assert(Form8.getName() == Form7.getName());
		assert(Form8.getGrade() == Form7.getGrade());

		//Copy assingment operator
		Form Form9("Bonjour");
		Form9 = Form6;
		assert(Form9.getName() == "Bonjour");
		assert(Form9.getGrade() == Form6.getGrade());
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat with incorrect grade values" + RESET);
		
		try {
			Form	Form2(0);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat correct increment and decrement" + RESET);
		
		Form	Form1("John", 75);
		
		std::cout << Form1 << std::endl;
		std::cout << ++Form1 << std::endl;
		std::cout << Form1++ << std::endl;
		std::cout << Form1 << std::endl;
		std::cout << --Form1 << std::endl;
		std::cout << Form1-- << std::endl;
		std::cout << Form1 << std::endl;
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat incorrect increment" + RESET);

		try {
			Form	Form1("John", 1);
	
			std::cout << Form1 << std::endl;
			std::cout << ++Form1 << std::endl;
			std::cout << Form1 << std::endl;
		}
		catch (const std::exception & e) {
			UI::printLine(e.what());
		}
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat incorrect decrement" + RESET);

		try {
			Form	Form1("John", 150);
	
			std::cout << Form1 << std::endl;
			std::cout << --Form1 << std::endl;
			std::cout << Form1 << std::endl;
		}
		catch (const std::exception & e) {
			UI::printLine(e.what());
		}
	}
}

