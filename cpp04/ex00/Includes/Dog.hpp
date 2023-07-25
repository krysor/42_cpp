#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal {


public:

	Dog( void );
	Dog( std::string type );
	Dog( const Dog& Dog );
	Dog&	operator=( const Dog& Dog );
	~Dog( void );

	void	makeSound( void ) const;

	const std::string&	getType( void ) const;
};

#endif