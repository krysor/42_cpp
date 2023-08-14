#include "Form.hpp"
#include "UI.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name(""), _signed(false), 
					_gradeToSign(GRADEMAX), _gradeToExecute(GRADEMAX) {
	UI::printLine("[Form] Default constructor called");
}

Form::Form( std::string name, long int gradeToSign, long int gradeToExecute )
			: _name(name), _signed(false), _gradeToSign(gradeToSign),
				_gradeToExecute(gradeToExecute) {
	UI::printLine("[Form] Default constructor called");
	Bureaucrat::checkGrade(gradeToSign);
	Bureaucrat::checkGrade(gradeToExecute);
}

Form::Form( const Form& other ) : _name(other._name), _signed(other._signed), 
					_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	UI::printLine("[Form] Copy constructor called");
}

Form&	Form::operator=( const Form& other ) {
	UI::printLine("[Form] Copy assignment operator called");
	this->_signed = other._signed;
	return (*this);
}

Form::~Form( void ) throw()
{
	UI::printLine("[Form] Destructor called");
}

const std::string&	Form::getName( void ) const
{
	return (this->_name);
}

bool	Form::getSigned( void ) const
{
	return (this->_signed);
}

int	Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high (smaller than 1)");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low (higher than 150)");
}

std::ostream&	operator<<( std::ostream& os,
							const Form& Form )
{
	os << Form.getName() + ", " + "form" + " "
		  + (Form.getSigned() ? "signed" : "unsigned") + " "
		  + "grade to sign:" + " "
		  		+ std::to_string(Form.getGradeToSign()) + " "
		  + "grade to execute:" + " "
		  		+ std::to_string(Form.getGradeToExecute()) + " ";
	return (os);
}
