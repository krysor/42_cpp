#include "UI.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) 
{
	/* [AMateria] tests don't compile because AMateria is 
		an abstract class (= interface) and cannot be instantiated */
	
	// UI::printLine("\n");
	// UI::printLine("Test [AMateria]\n");
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
		Ice	Ice2(Ice1);
		Ice	Ice3;

		Ice3 = Ice2;

		assert(Ice1.getType() == "ice");
		assert(Ice2.getType() == "ice");
		assert(Ice3.getType() == "ice");

		AMateria* IcePnt = Ice1.clone();
		assert(IcePnt->getType() == "ice");
		delete IcePnt;
	}

	UI::printLine("\n");
	UI::printLine("Test [Cure]\n");
	{
		Cure	Cure1;
		Cure	Cure2(Cure1);
		Cure	Cure3;

		Cure3 = Cure2;

		assert(Cure1.getType() == "cure");
		assert(Cure2.getType() == "cure");
		assert(Cure3.getType() == "cure");

		AMateria* CurePnt = Cure1.clone();
		assert(CurePnt->getType() == "cure");
		delete CurePnt;
	}

	return (EXIT_SUCCESS);
}
