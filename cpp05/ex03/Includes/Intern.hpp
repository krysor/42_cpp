#pragma once
#ifndef __INTERN_H__
#define __INTERN_H__

#include "AForm.hpp"

class Intern {


public:

	Intern( void );
	Intern( const Intern& other );
	Intern&	operator=( const Intern& other );
	~Intern( void );

	Form*	makeForm( std::string nameForm, std::string targetForm );
};


#endif