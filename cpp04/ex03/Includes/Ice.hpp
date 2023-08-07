#pragma once
#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {


public:

	Ice( void );
	Ice( const Ice& other );
	Ice&	operator=( const Ice& other );
	~Ice( void );

	std::string const & getType() const;
	
	AMateria* clone() const;
	void use(ICharacter& target);

};

#endif