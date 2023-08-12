#pragma once
#ifndef __FORM_H__
#define __FORM_H__


class Form {

private:

	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;


public:

	Form( void );
	Form( std::string name, bool sign, 
			long int gradeToSign, long int gradeToExecute );
	Form( const Form& other );
	Form&	operator=( const Form& other );
	~Form( void ) throw();

	const std::string&	getName() const;
	bool				getSigned( void ) const;
	const int			getGradeToSign( void ) const;
	const int			getGradeToExecute( void ) const;

	class GradeTooHighException : public std::exception {
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char* what() const throw();
	};

};

#endif