#pragma once
#ifndef __PRESIDENTIALPARDONFORM_H__
#define __PRESIDENTIALPARDONFORM_H__

#include "AForm.hpp"

#define PPDEFAULTGRADETOSIGN 25
#define PPDEFAULTGRADETOEXEC 5

class PresidentialPardonForm : public Form {
	
private:

	std::string	_target;

public:

	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( const PresidentialPardonForm& other );
	PresidentialPardonForm&	operator=( const PresidentialPardonForm& other );
	~PresidentialPardonForm( void ) throw();

	const std::string&	getTarget( void ) const;

	void	executeAction( void ) const;
};

#endif