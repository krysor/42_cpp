#include "PresidentialPardonForm.hpp"
#include "UI.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("PresidentialPardonForm", PPDEFAULTGRADETOSIGN, PPDEFAULTGRADETOEXEC)
{
	UI::printLine("[PresidentialPardonForm] Default constructor called");
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("PresidentialPardonForm", PPDEFAULTGRADETOSIGN, PPDEFAULTGRADETOEXEC)
{
	UI::printLine("[PresidentialPardonForm] Target constructor called");
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other )
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	return ;
}
