#include "UI.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// int main( void ) 
// {
// 	UI::printLine("\n");
// 	UI::printLine("Test [Ice]\n");
// 	{
// 		Ice	Ice1;
// 		Ice	Ice2(Ice1);
// 		Ice	Ice3;

// 		Ice3 = Ice2;

// 		assert(Ice1.getType() == "ice");
// 		assert(Ice2.getType() == "ice");
// 		assert(Ice3.getType() == "ice");

// 		AMateria* IcePnt = Ice1.clone();
// 		assert(IcePnt->getType() == "ice");
// 		delete IcePnt;

// 	}

// 	UI::printLine("\n");
// 	UI::printLine("Test [Cure]\n");
// 	{
// 		Cure	Cure1;
// 		Cure	Cure2(Cure1);
// 		Cure	Cure3;

// 		Cure3 = Cure2;

// 		assert(Cure1.getType() == "cure");
// 		assert(Cure2.getType() == "cure");
// 		assert(Cure3.getType() == "cure");

// 		AMateria* CurePnt = Cure1.clone();
// 		assert(CurePnt->getType() == "cure");
// 		delete CurePnt;
// 	}

// 	UI::printLine("\n");
// 	UI::printLine("Test [Character] Simple initialization and getName()\n");
// 	{
// 		Character	Character1;
// 		Character	Character2("characterName");
// 		Character	Character3(Character1);
// 		Character	Character4;

// 		Character4 = Character2;
		
// 		assert(Character1.getName() == "");
// 		assert(Character2.getName() == "characterName");
// 		assert(Character3.getName() == "");
// 		assert(Character4.getName() == "characterName");
// 	}

// 	UI::printLine("\n");
// 	UI::printLine("Test [Character] equip, unequip, use\n");
// 	{
// 		Character	Character1("testCharacter");
// 		Character	Character2("testTarget");
// 		Ice			Ice;
// 		Cure		Cure;
// 		AMateria*	arrPnt[INVENTORYSIZE + 1];

// 		//try to equip nullpt
// 		Character1.equip(nullptr);

// 		//prepare an array of Materias
// 		for (int i = 0 ; i <= INVENTORYSIZE / 2 ; i++) {
// 			arrPnt[i] = Ice.clone();
// 		}
// 		for (int i = INVENTORYSIZE / 2 ; i <= INVENTORYSIZE ; i++) {
// 			arrPnt[i] = Cure.clone();
// 		}

// 		//equip all Materias
// 		for (int i = 0 ; i <= INVENTORYSIZE ; i++) {
// 			Character1.equip(arrPnt[i]);
// 		}

// 		//use all Materias
// 		for (int i = -1 ; i <= INVENTORYSIZE ; i++) {
// 			Character1.use(i, Character2);
// 		}

// 		//unequip all Materias
// 		for (int i = 0 ; i < INVENTORYSIZE + 1 ; i++) {
// 			Character1.unequip(i);
// 		}

// 		//delete all Materias
// 		for (int i = 0 ; i <= INVENTORYSIZE ; i++) {
// 			if (arrPnt[i] != nullptr) {
// 				delete arrPnt[i];
// 			}
// 		}
// 	}

// 	UI::printLine("\n");
// 	UI::printLine("Test [MateriaSource]\n");
// 	{
// 		MateriaSource	MateriaSource1;
// 		Ice				Ice1;
// 		Cure			Cure1;
// 		AMateria*		AMateriaPnt;

// 		UI::printLine("\n");

// 		//learnMateria + createMateria: single Materia
// 		MateriaSource1.learnMateria(&Ice1);
// 		AMateriaPnt = MateriaSource1.createMateria("ice");
// 		assert(AMateriaPnt->getType() == "ice");
// 		delete AMateriaPnt;

// 		UI::printLine("\n");

// 		//learnMateria + createMateria: nonexisting Materia
// 		AMateriaPnt = MateriaSource1.createMateria("dice");
// 		assert(AMateriaPnt == nullptr);

// 		UI::printLine("\n");

// 		//learnMateria: (x > INVENTORYSIZE) Materia's
// 		MateriaSource1.learnMateria(&Cure1);
// 		MateriaSource1.learnMateria(&Ice1);
// 		MateriaSource1.learnMateria(&Cure1);
// 		MateriaSource1.learnMateria(&Ice1);

// 		UI::printLine("\n");

// 		//createMateria: multiple Materia's
// 		AMateriaPnt = MateriaSource1.createMateria("ice");
// 		assert(AMateriaPnt->getType() == "ice");
// 		delete AMateriaPnt;
// 		AMateriaPnt = MateriaSource1.createMateria("cure");
// 		assert(AMateriaPnt->getType() == "cure");
// 		delete AMateriaPnt;
// 		AMateriaPnt = MateriaSource1.createMateria("pure");
// 		assert(AMateriaPnt == nullptr);
// 		delete AMateriaPnt;

// 		UI::printLine("\n");
// 	}

// 	//leak check
// 	// UI::printLine("\n");
// 	// system("leaks ex03");

// 	return (EXIT_SUCCESS);
// }

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}