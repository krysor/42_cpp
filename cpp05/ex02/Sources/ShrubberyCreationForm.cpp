#include "ShrubberyCreationForm.hpp"
#include "UI.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("ShrubberyCreationForm", SCDEFAULTGRADETOSIGN, SCDEFAULTGRADETOEXEC)
{
	UI::printLine("[ShrubberyCreationForm] Default constructor called");
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", SCDEFAULTGRADETOSIGN, SCDEFAULTGRADETOEXEC)
{
	UI::printLine("[ShrubberyCreationForm] Target constructor called");
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
	: AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute())
{
	UI::printLine("[ShrubberyCreationForm] Copy constructor called");
	this->_target = other._target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	UI::printLine("[ShrubberyCreationForm] Copy assignment operator called");
	this->_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) throw()
{
	UI::printLine("[ShrubberyCreationForm] Destructor called");
}

const std::string&	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::executeAction( void )
{
	std::ofstream	output;

	output.open((target + "_shrubbery").c_str(),
					std::ios::out | std::ios::trunc);
	if (output == NULL) {
		std::cout << "Opening of the output file failed" << std::endl;
		return ;
	}
	output << "ASCII trees";	
	output.close();
}
