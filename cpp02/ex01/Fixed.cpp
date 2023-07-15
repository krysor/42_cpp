#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	operator=(fixed);
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	int	rawBits = integer << _nbFractionalBits;
	setRawBits(rawBits);
}

Fixed::Fixed(const float floatingPointNumber)
{
	std::cout << "Float constructor called" << std::endl;
	float	multiplier 		= 1 << this->_nbFractionalBits;
	float	product			= floatingPointNumber * multiplier;
	int		rawBits			= roundf(product);
	setRawBits(rawBits);
}

Fixed&	Fixed::operator=( const Fixed& fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	float	divisor		= 1 << _nbFractionalBits;
	float	quotient	= this->getRawBits() / divisor;
	return (quotient);
}

int 	Fixed::toInt( void ) const
{
	return (getRawBits() >> _nbFractionalBits);
}

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed )
{
	os << fixed.toFloat();
	return (os);
}