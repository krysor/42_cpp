#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>

class Bureaucrat {


private:

	const std::string	_name;
	unsigned char		_grade;


public:

	Bureaucrat( void );
	Bureaucrat( std::string name );
	Bureaucrat( long int grade );
	Bureaucrat( std::string name, long int grade );
	Bureaucrat( long int grade, std::string name );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat&	operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	const std::string&	getName() const;
	unsigned char		getGrade() const;

};

#endif