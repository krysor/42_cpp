#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <exception>

#define GRADEMAX 1
#define GRADEMIN 150

class Bureaucrat {


private:

	const std::string	_name;
	int					_grade;


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
	int					getGrade() const;

	static void			checkGrade(long int grade);

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	const Bureaucrat&	operator++( void );
	const Bureaucrat	operator++( int );
	const Bureaucrat&	operator--( void );
	const Bureaucrat	operator--( int );


};

std::ostream&	operator <<( std::ostream& os, const Bureaucrat& bureaucrat );

#endif