#pragma once
#ifndef __MATERIASOURCE_H__
#define __MATERIASOURCE_H__

#include "IMateriaSource.hpp"
#include "Character.hpp"

class MateriaSource : public IMateriaSource, public Character {

public:

	MateriaSource( void );
	MateriaSource( const MateriaSource& other );
	MateriaSource&	operator=( const MateriaSource& other );
	~MateriaSource( void );

	void 		learnMateria(AMateria*);
	AMateria*	createMateria(std::string const & type);

};

#endif