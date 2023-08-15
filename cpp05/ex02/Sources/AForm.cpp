#include "AForm.hpp"
#include "UI.hpp"

void	AForm::checkGrade(long int grade) {
	if (grade < GRADEMAX) {
		throw AForm::GradeTooHighException();
    }
	else if (grade > GRADEMIN) {
		throw AForm::GradeTooLowException();
    }
}

AForm::AForm( void ) : _name(""), _signed(false), 
					_gradeToSign(GRADEMAX), _gradeToExecute(GRADEMAX) {
	UI::printLine("[AForm] Default constructor called");
}

AForm::AForm( std::string name, long int gradeToSign, long int gradeToExecute )
			: _name(name), _signed(false), _gradeToSign(gradeToSign),
				_gradeToExecute(gradeToExecute) {
	UI::printLine("[AForm] Input constructor called");
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);
}

AForm::AForm( const AForm& other ) : _name(other._name), _signed(false), 
					_gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	UI::printLine("[AForm] Copy constructor called");
}

AForm&	AForm::operator=( const AForm& other ) {
	UI::printLine("[AForm] Copy assignment operator called");
	this->_signed = other._signed;
	return (*this);
}

AForm::~AForm( void ) throw()
{
	UI::printLine("[AForm] Destructor called");
}

const std::string&	AForm::getName( void ) const
{
	return (this->_name);
}

bool	AForm::getSigned( void ) const
{
	return (this->_signed);
}

int	AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExecute( void ) const
{
	return (this->_gradeToExecute);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char* AForm::UnsignedException::what() const throw()
{
	return ("The form is unsigned");
}

void	AForm::beSigned( Bureaucrat& bureaucrat )
{
	if (this->_signed == true)
		return ;
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

bool	AForm::execute(Bureaucrat const & executor) const
{
	if (this->_signed == false)
		throw AForm::UnsignedException();
	else if (this->_gradeToExecute < executor.getGrade())
		throw Bureaucrat::GradeTooLowException();
	else
		this->executeAction();
	return (true);
}

void	AForm::executeAction( void ) const
{
	return ;
}

std::ostream&	operator<<( std::ostream& os,
							const AForm& AForm )
{
	os << "AForm" << std::endl
	   << std::left << std::setw(20) << "Name" << ": "
		  + AForm.getName() << std::endl
	   << std::setw(20) << "Status" << ": "
	   	  + std::string(AForm.getSigned() ? "signed" : "unsigned") << std::endl
	   << std::setw(20) << "Grade to sign" << ": "
	   	  + std::to_string(AForm.getGradeToSign()) << std::endl
	   << std::setw(20) << "Grade to execute" << ": "
		  + std::to_string(AForm.getGradeToExecute()) << std::endl;
	return (os);
}
