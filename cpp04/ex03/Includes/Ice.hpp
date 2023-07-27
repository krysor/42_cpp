#pragma once
#ifndef __ICE_H__
#define __ICE_H__

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria {


public:

	Ice( void );
	Ice( std::string const & type );
	Ice( const Ice& other );
	Ice&	operator=( const Ice& other );
	~Ice( void );

	std::string const & getType() const;
	virtual Ice* clone() const;
	//void use(ICharacter& target);

};

#endif