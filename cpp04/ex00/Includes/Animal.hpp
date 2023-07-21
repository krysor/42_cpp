#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class Animal {


protected:

	std::string	_type;


public:

	Animal( void );
	Animal( std::string type );
	Animal( const Animal& animal );
	Animal&	operator=( const Animal& animal );
	virtual ~Animal( void );

	virtual void	makeSound( void ) const;

	const std::string&	getType( void ) const;
	void				setType( const std::string type );
};

#endif