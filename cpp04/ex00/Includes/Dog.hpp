#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal {


protected:

	std::string	_type;


public:

	Dog( void );
	Dog( std::string type );
	Dog( const Dog& Dog );
	Dog&	operator=( const Dog& Dog );
	~Dog( void );

	void	makeSound( void ) const;
};

#endif