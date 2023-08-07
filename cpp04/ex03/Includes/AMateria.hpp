#pragma once
#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {


protected:

	std::string	_type;

public:

	AMateria( void );
	AMateria( std::string const & type );
	AMateria( const AMateria& other );
	AMateria&	operator=( const AMateria& other );
	virtual ~AMateria( void );

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif