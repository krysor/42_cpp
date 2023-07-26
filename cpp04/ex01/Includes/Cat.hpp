#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal {

private:

	Brain*	_brain;

public:

	Cat( void );
	Cat( std::string type );
	Cat( const Cat& other );
	Cat&	operator=( const Cat& other );
	~Cat( void );

	void	makeSound( void ) const;

	const std::string&	getType( void ) const;
};

#endif