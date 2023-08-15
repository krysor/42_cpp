#pragma once
#ifndef __ROBOTOMYREQUESTFORM_H__
#define __ROBOTOMYREQUESTFORM_H__

#include "AForm.hpp"

#define RRDEFAULTGRADETOSIGN 72
#define RRDEFAULTGRADETOEXEC 45

class RobotomyRequestForm : public Form {
	
private:

	std::string	_target;

public:

	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( const RobotomyRequestForm& other );
	RobotomyRequestForm&	operator=( const RobotomyRequestForm& other );
	~RobotomyRequestForm( void ) throw();

	const std::string&	getTarget( void ) const;

	void	executeAction( void ) const;
};

#endif