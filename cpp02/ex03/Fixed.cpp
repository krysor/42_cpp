#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	operator=(fixed);
}

Fixed::Fixed(const int integer)
{
	//std::cout << "Int constructor called" << std::endl;
	setRawBits(integer << _nbFractionalBits);
}

Fixed::Fixed(const float floatingPointNumber)
{
	//std::cout << "Float constructor called" << std::endl;
	float	multiplier 		= 1 << this->_nbFractionalBits;
	float	product			= floatingPointNumber * multiplier;
	int		rawBits			= roundf(product);
	setRawBits(rawBits);
}

Fixed&	Fixed::operator=( const Fixed& fixed )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed(void)
{
	//std::cout << "Destructor called" << std::endl;
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

bool	Fixed::operator >(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator <(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (operator>(other) || operator==(other));
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (operator<(other) || operator==(other));
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (!operator==(other));
}

const Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed 	fixed 		= Fixed();
	int		sumRawBits 	= this->getRawBits() + other.getRawBits();
	fixed.setRawBits(sumRawBits);
	return (Fixed(fixed));
}

const Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed 	fixed 		= Fixed();
	int		difference	= this->getRawBits() - other.getRawBits();
	fixed.setRawBits(difference);
	return (Fixed(fixed));
}

const Fixed	Fixed::operator*(const Fixed& other) const
{
	int		product;
	int		divisor;
	int		quotient;
	Fixed 	fixed;

	product		=	this->getRawBits() * other.getRawBits();
	divisor 	=	1 << _nbFractionalBits;
	quotient	=	product / divisor;
	fixed.setRawBits(quotient);
	return (Fixed(fixed));
}

const Fixed	Fixed::operator/(const Fixed& other) const
{
	double	quotient;
	int		multiplier;
	int		product;
	Fixed 	fixed;

	quotient	=	(double)this->getRawBits() / other.getRawBits();
	multiplier 	=	1 << _nbFractionalBits;
	product		=	roundf(quotient * multiplier);
	fixed.setRawBits(product);
	return (Fixed(fixed));
}

const Fixed&	Fixed::operator++( void )
{
	int	rawBits;

	rawBits = this->getRawBits();
	rawBits++;
	setRawBits(rawBits);
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	int		rawBits;
	Fixed	fixed = Fixed(*this);

	rawBits = this->getRawBits();
	rawBits++;
	setRawBits(rawBits);
	return (fixed);
}

const Fixed&	Fixed::operator--( void )
{
	int	rawBits;

	rawBits = this->getRawBits();
	rawBits--;
	setRawBits(rawBits);
	return (*this);
}

const Fixed		Fixed::operator--( int )
{
	int		rawBits;
	Fixed	fixed = Fixed(*this);

	rawBits = this->getRawBits();
	rawBits--;
	setRawBits(rawBits);
	return (fixed);
}

const Fixed&	Fixed::min(Fixed& fixedA, Fixed& fixedB)
{
	if (fixedA.getRawBits() > fixedB.getRawBits())
		return (fixedB);
	return (fixedA);
}

const Fixed&	Fixed::min(const Fixed& fixedA, const Fixed& fixedB)
{
	if (fixedA.getRawBits() > fixedB.getRawBits())
		return (fixedB);
	return (fixedA);
}

const Fixed&	Fixed::max(Fixed& fixedA, Fixed& fixedB)
{
	if (fixedA.getRawBits() < fixedB.getRawBits())
		return (fixedB);
	return (fixedA);
}

const Fixed&	Fixed::max(const Fixed& fixedA, const Fixed& fixedB)
{
	if (fixedA.getRawBits() < fixedB.getRawBits())
		return (fixedB);
	return (fixedA);
}

std::ostream&	operator<<( std::ostream& os, const Fixed& fixed )
{
	os << fixed.toFloat();
	return (os);
}