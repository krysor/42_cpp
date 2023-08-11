#pragma once
#ifndef __WRONGCAT_H__
#define __WRONGCAT_H__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {


public:

	WrongCat( void );
	WrongCat( std::string type );
	WrongCat( const WrongCat& other );
	WrongCat&	operator=( const WrongCat& other );
	~WrongCat( void );

	void	makeSound( void ) const;

	const std::string&	getType( void ) const;
};

#endif