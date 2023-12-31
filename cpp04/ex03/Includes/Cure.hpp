#pragma once
#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria {


public:

	Cure( void );
	Cure( const Cure& other );
	Cure&	operator=( const Cure& other );
	~Cure( void );

	std::string const & getType() const;
	
	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif