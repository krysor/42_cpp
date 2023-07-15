#pragma once
#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl {


private:

	void debug( void ) const;
	void info( void ) const;
	void warning( void ) const;
	void error( void ) const;


public:

	Harl( void );
	~Harl( void );

	void complain( std::string level ) const;


};

#endif