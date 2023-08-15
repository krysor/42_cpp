#pragma once
#ifndef __SHRUBBERYCREATIONFORM_H__
#define __SHRUBBERYCREATIONFORM_H__

#include "AForm.hpp"
#include <fstream>

#define SCDEFAULTGRADETOSIGN 145
#define SCDEFAULTGRADETOEXEC 137

class ShrubberyCreationForm : public AForm {
	
private:

	std::string	_target;

public:

	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( const ShrubberyCreationForm& other );
	ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& other );
	~ShrubberyCreationForm( void ) throw();

	const std::string&	getTarget( void ) const;

	void	executeAction( void );
};

#endif