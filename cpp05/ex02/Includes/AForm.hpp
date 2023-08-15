#pragma once
#ifndef __AFORM_H__
#define __AFORM_H__

#include <string>
#include "Bureaucrat.hpp"
#include <iomanip>

class Bureaucrat;

class AForm {

private:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;


public:

	AForm( void );
	AForm( std::string name, long int gradeToSign, 
			long int gradeToExecute );
	AForm( const AForm& other );
	AForm&	operator=( const AForm& other );
	~AForm( void ) throw();

	virtual	void	execute(Bureaucrat const & executor) const = 0;

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

	void	beSigned(Bureaucrat& bureaucrat);

};

std::ostream&	operator<<( std::ostream& os,
							const AForm& AForm );

#endif