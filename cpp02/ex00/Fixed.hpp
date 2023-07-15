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
	Fixed&	operator=( const Fixed& fixed );
	~Fixed( void );

	int		getRawBits( void ) const;
	void 	setRawBits( int const raw );

};

#endif