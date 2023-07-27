#pragma once
#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <string>

class Character {


protected:

	std::string	_type;

public:

	Character( void );
	Character( std::string const & type );
	Character( const Character& other );
	Character&	operator=( const Character& other );
	~Character( void );

	std::string const & getType() const;
	virtual Character* clone() const = 0;
	//virtual void use(ICharacter& target);

};

#endif