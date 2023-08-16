#include "UI.hpp"
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
	{
		UI::printLine(RED + "Test Intern unexisting form" + RESET);
		
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	{
		UI::printLine(RED + "Test Intern existing form" + RESET);
		
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "cllequen");
		delete rrf;
	}
	//system("leaks ex03");
}

