#pragma once
#ifndef __WRONGANIMAL_H__
#define __WRONGANIMAL_H__

#include <string>

class WrongAnimal {


protected:

	std::string	type;


public:

	WrongAnimal( void );
	WrongAnimal( std::string type );
	WrongAnimal( const WrongAnimal& other );
	WrongAnimal&	operator=( const WrongAnimal& other );
	virtual ~WrongAnimal( void );

	virtual void	makeSound( void ) const;

	const std::string&	getType( void ) const;
	void				setType( const std::string type );
};

#endif