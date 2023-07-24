#pragma once
#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"

class Cat : public Animal {


public:

	Cat( void );
	Cat( std::string type );
	Cat( const Cat& Cat );
	Cat&	operator=( const Cat& Cat );
	~Cat( void );

	void	makeSound( void ) const;
};

#endif