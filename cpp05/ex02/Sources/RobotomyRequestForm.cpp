#include "RobotomyRequestForm.hpp"
#include "UI.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("RobotomyRequestForm", RRDEFAULTGRADETOSIGN, RRDEFAULTGRADETOEXEC)
{
	UI::printLine("[RobotomyRequestForm] Default constructor called");
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", RRDEFAULTGRADETOSIGN, RRDEFAULTGRADETOEXEC)
{
	UI::printLine("[RobotomyRequestForm] Target constructor called");
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other )
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	UI::printLine("[RobotomyRequestForm] Copy constructor called");
	this->_target = other._target;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	UI::printLine("[RobotomyRequestForm] Copy assignment operator called");
	this->_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) throw()
{
	UI::printLine("[RobotomyRequestForm] Destructor called");
}

const std::string&	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::dummyFunction( void )
{
	return ;
}
