#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <exception>

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
	~Bureaucrat( void ) throw();

	const std::string&	getName() const;
	unsigned char		getGrade() const;

	class GradeTooHighException : public exception {
		const char* what() const throw();
	}

	class GradeTooLowException : public exception {
		const char* what() const throw();
	}
};

#endif