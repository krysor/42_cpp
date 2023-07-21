#pragma once
#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <string>

class Animal {


protected:

	std::string	type;


public:

	Animal( void );
	Animal( std::string type );
	Animal( const Animal& animal );
	Animal&	operator=( const Animal& animal );
	~Animal( void );

	const std::string&	getType( void ) const;
	void				setType( const std::string type );
};

#endif