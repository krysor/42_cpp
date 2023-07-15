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

	bool	operator >(const Fixed& other) const;
	bool	operator <(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	const Fixed	operator+(const Fixed& other) const;
	const Fixed	operator-(const Fixed& other) const;
	const Fixed	operator*(const Fixed& other) const;
	const Fixed	operator/(const Fixed& other) const;

	const Fixed&	operator++( void );
	const Fixed		operator++( int );
	const Fixed&	operator--( void );
	const Fixed		operator--( int );

	static const Fixed&	min(Fixed& fixedA, Fixed& fixedB);
	static const Fixed&	min(const Fixed& fixedA, const Fixed& fixedB);
	static const Fixed&	max(Fixed& fixedA, Fixed& fixedB);
	static const Fixed&	max(const Fixed& fixedA, const Fixed& fixedB);
};

std::ostream&	operator <<( std::ostream& os, const Fixed& fixed );

#endif