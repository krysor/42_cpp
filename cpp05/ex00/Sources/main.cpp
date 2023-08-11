#include "UI.hpp"
#include "Bureaucrat.hpp"

int main( void ) 
{
	{
		UI::printLine("Test Bureaucraat");

		Bureaucrat	bureaucrat1;
		assert(bureaucrat1.getName().empty());
		assert(bureaucrat1.getGrade() == 150);

		Bureaucrat	bureaucrat2("Gwenda");
		assert(bureaucrat1.getName() == "Gwenda");
		assert(bureaucrat1.getGrade() == 150);

		Bureaucrat	bureaucrat3(0);
		assert(bureaucrat1.getName().empty());
		assert(bureaucrat1.getGrade() == 0);
	}

	UI::printLine("\n");
}

