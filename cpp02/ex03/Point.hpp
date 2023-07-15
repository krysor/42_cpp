#pragma once
#ifndef __POINT_H__
#define __POINT_H__

#include "Fixed.hpp"

class Point {


private:

	Fixed const	_x;
	Fixed const	_y;	

public:

	Point( void );
	Point( float x, float y );
	Point( const Point& point );
	Point&	operator=( const Point& point );
	~Point( void );

	const Fixed&	getX( void ) const;
	const Fixed&	getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif