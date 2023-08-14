#pragma once
#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const Form& other );
	ShrubberyCreationForm&	operator=( const Form& other );
	~ShrubberyCreationForm( void ) throw();

	void	dummyFunction( void );
};

#endif