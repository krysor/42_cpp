#include "UI.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void ) 
{
	{
		UI::printLine(RED + "Test Intern" + RESET);

		Intern	Intern1;
		Intern	Intern2(Intern1);
		Intern	Intern3;

		Intern3 = Intern2;
	}
}

