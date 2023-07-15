#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point( float x, float y ) : _x(x), _y(y)
{
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point( const Point& point ) : _x(point._x), _y(point._y)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point&	Point::operator=( const Point& point )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	(void)point;
	return (*this);
}

Point::~Point( void )
{
	//std::cout << "Default destructor called" << std::endl;
}

const Fixed&	Point::getX( void ) const
{
	return (this->_x);
}

const Fixed&	Point::getY( void ) const
{
	return (this->_y);
}
