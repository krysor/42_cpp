#include "MateriaSource.hpp"
#include "UI.hpp"

MateriaSource::MateriaSource( void ) : Character() {
	UI::printLine("[MateriaSource] Default constructor called");
}

MateriaSource::MateriaSource( const MateriaSource& other ) : Character() {
	UI::printLine("[MateriaSource] Copy constructor called");
	(void)other;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {
	UI::printLine("[MateriaSource] Copy assignment operator called");
	(void)other;
	return (*this);
}

MateriaSource::~MateriaSource( void ) {
	UI::printLine("[MateriaSource] Destructor called");
}

void 		MateriaSource::learnMateria(AMateria*) {
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	(void)type;
	return (nullptr);
}
