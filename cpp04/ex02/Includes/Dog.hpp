#pragma once
#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"

class Dog : public Animal {

private:

	Brain*	_brain;

public:

	Dog( void );
	Dog( std::string type );
	Dog( const Dog& other );
	Dog&	operator=( const Dog& other );
	~Dog( void );

	void	makeSound( void ) const;

	const std::string&	getType( void ) const;
};

#endif