#include "PresidentialPardonForm.hpp"
#include "UI.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form("PresidentialPardonForm", PPDEFAULTGRADETOSIGN, PPDEFAULTGRADETOEXEC)
{
	UI::printLine("[PresidentialPardonForm] Default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: Form("PresidentialPardonForm", PPDEFAULTGRADETOSIGN, PPDEFAULTGRADETOEXEC)
{
	UI::printLine("[PresidentialPardonForm] Target constructor called");
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: Form(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	UI::printLine("[PresidentialPardonForm] Copy constructor called");
	this->_target = other._target;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	UI::printLine("[PresidentialPardonForm] Copy assignment operator called");
	this->_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) throw()
{
	UI::printLine("[PresidentialPardonForm] Destructor called");
}

const std::string&	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void	PresidentialPardonForm::executeAction( void ) const
{
	UI::printLine(this->getTarget() + " has been pardoned by Zaphod Beeblebrox.");
}
