#include "UI.hpp"
#include "Bureaucrat.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test Bureaucraat with correct values" + RESET);

		//Default constructor
		Bureaucrat	bureaucrat1;
		assert(bureaucrat1.getName().empty());
		assert(bureaucrat1.getGrade() == 150);

		//Name constructor
		Bureaucrat	bureaucrat2("Gwenda");
		assert(bureaucrat2.getName() == "Gwenda");
		assert(bureaucrat2.getGrade() == 150);

		Bureaucrat	bureaucrat3("");
		assert(bureaucrat3.getName() == "");

		//Grade constructor
		Bureaucrat	bureaucrat4(1);
		assert(bureaucrat4.getGrade() == 1);

		Bureaucrat	bureaucrat5(150);
		assert(bureaucrat5.getGrade() == 150);

		//Name grade constructor
		Bureaucrat	bureaucrat6("Stephan", 75);
		assert(bureaucrat6.getName() == "Stephan");
		assert(bureaucrat6.getGrade() == 75);

		//Grade name constructor
		Bureaucrat	bureaucrat7(1, "Xavier");
		assert(bureaucrat7.getName() == "Xavier");
		assert(bureaucrat7.getGrade() == 1);

		//Copy constructor
		Bureaucrat bureaucrat8(bureaucrat7);
		assert(bureaucrat8.getName() == bureaucrat7.getName());
		assert(bureaucrat8.getGrade() == bureaucrat7.getGrade());

		//Copy assingment operator
		Bureaucrat bureaucrat9("Bonjour");
		bureaucrat9 = bureaucrat6;
		assert(bureaucrat9.getName() == "Bonjour");
		assert(bureaucrat9.getGrade() == bureaucrat6.getGrade());
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat with incorrect grade values" + RESET);
		
		try {
			Bureaucrat	bureaucrat2(0);
		}
		catch (std::exception & e) {
			UI::printLine(e.what());
		}
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat correct increment and decrement" + RESET);
		
		Bureaucrat	bureaucrat1("John", 75);
		
		std::cout << bureaucrat1 << std::endl;
		std::cout << ++bureaucrat1 << std::endl;
		std::cout << bureaucrat1++ << std::endl;
		std::cout << bureaucrat1 << std::endl;
		std::cout << --bureaucrat1 << std::endl;
		std::cout << bureaucrat1-- << std::endl;
		std::cout << bureaucrat1 << std::endl;
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat incorrect increment" + RESET);

		try {
			Bureaucrat	bureaucrat1("John", 1);
	
			std::cout << bureaucrat1 << std::endl;
			std::cout << ++bureaucrat1 << std::endl;
			std::cout << bureaucrat1 << std::endl;
		}
		catch (const std::exception & e) {
			UI::printLine(e.what());
		}
	}

	UI::printLine("\n");

	{
		UI::printLine(RED + "Test Bureaucraat incorrect decrement" + RESET);

		try {
			Bureaucrat	bureaucrat1("John", 150);
	
			std::cout << bureaucrat1 << std::endl;
			std::cout << --bureaucrat1 << std::endl;
			std::cout << bureaucrat1 << std::endl;
		}
		catch (const std::exception & e) {
			UI::printLine(e.what());
		}
	}
}

