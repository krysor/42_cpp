#pragma once
#ifndef __FIXED_H__
#define __FIXED_H__

#include <iostream>

class Fixed {


private:

	int 				_rawBits;
	static const int	_nbFractionalBits = 8;

public:

	Fixed( void );
	Fixed( const Fixed& fixed );
	Fixed( const int integer );
	Fixed( const float floatingPointNumber );
	~Fixed( void );
	Fixed&	operator=( const Fixed& fixed );

	int		getRawBits( void ) const;
	void 	setRawBits( int const raw );
	
	float 	toFloat( void ) const;
	int 	toInt( void ) const;

};

std::ostream&	operator <<( std::ostream& os, const Fixed& fixed );

#endif