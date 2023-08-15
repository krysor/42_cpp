#include "AForm.hpp"

void	Form::checkGrade(long int grade) {
	if (grade < GRADEMAX) {
		throw Form::GradeTooHighException();
    }
	else if (grade > GRADEMIN) {
		throw Form::GradeTooLowException();
    }
}

Form::Form( void ) : _name(""), _signed(false), 
					_gradeToSign(GRADEMAX), _gradeToExecute(GRADEMAX) {
	UI::printLine("[Form] Default constructor called");
}

Form::Form( std::string name, long int gradeToSign, long int gradeToExecute )
			: _name(name), _signed(false), _gradeToSign(gradeToSign),
				_gradeToExecute(gradeToExecute) {
	UI::printLine("[Form] Input constructor called");
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

Form::Form( const Form& other ) : _name(other._name), _signed(false), 
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
	return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char* Form::UnsignedException::what() const throw()
{
	return ("The form is unsigned");
}

void	Form::beSigned( Bureaucrat& bureaucrat )
{
	if (this->_signed == true)
		return ;
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

bool	Form::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw Form::UnsignedException();
	else if (this->_gradeToExecute < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->executeAction();
	return (true);
}

void	Form::executeAction( void ) const
{
	return ;
}

std::ostream&	operator<<( std::ostream& os,
							const Form& Form )
{
	os << "Form" << std::endl
	   << std::left << std::setw(20) << "Name" << ": "
		  + Form.getName() << std::endl
	   << std::setw(20) << "Status" << ": "
	   	  + std::string(Form.getSigned() ? "signed" : "unsigned") << std::endl
	   << std::setw(20) << "Grade to sign" << ": "
	   	  + std::to_string(Form.getGradeToSign()) << std::endl
	   << std::setw(20) << "Grade to execute" << ": "
		  + std::to_string(Form.getGradeToExecute()) << std::endl;
	return (os);
}
