#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <string>
#include "Bureaucrat.hpp"
#include <iomanip>
#include "UI.hpp"

class Bureaucrat;

class Form {

private:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;


public:

	Form( void );
	Form( std::string name, long int gradeToSign, 
			long int gradeToExecute );
	Form( const Form& other );
	Form&	operator=( const Form& other );
	~Form( void ) throw();

	bool			execute(Bureaucrat const & executor) const;
	virtual	void	executeAction( void ) const = 0;

	const std::string&	getName( void ) const;
	bool				getSigned( void ) const;
	int					getGradeToSign( void ) const;
	int					getGradeToExecute( void ) const;

	static void			checkGrade(long int grade);

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

	class UnsignedException : public std::exception {
		const char* what() const throw();
	};

	void	beSigned(Bureaucrat& bureaucrat);

};

std::ostream&	operator<<( std::ostream& os,
							const Form& Form );

#endif