#include "UI.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) 
{
	UI::printLine("\n");
	UI::printLine("Test [AMateria]\n");
	{
		// AMateria	AMateria1;
		// AMateria	AMateria2("someType");
		// AMateria	AMateria3(AMateria1);
		// AMateria	AMateria4;

		// AMateria4 = AMateria2;
	}

	UI::printLine("\n");
	UI::printLine("Test [Ice]\n");
	{
		Ice	Ice1;
		Ice	Ice2("someType");
		Ice	Ice3(Ice1);
		Ice	Ice4;

		Ice4 = Ice2;
	}

	UI::printLine("\n");
	UI::printLine("Test [Cure]\n");
	{
		Cure	Cure1;
		Cure	Cure2("someType");
		Cure	Cure3(Cure1);
		Cure	Cure4;

		Cure4 = Cure2;
	}

	return (EXIT_SUCCESS);
}
