#include "Bureaucrat.hpp"
#include "UI.hpp"

void	checkGrade(long int grade) {
	if (grade < 1) {
		throw std::invalid_argument( "GradeTooHighException" );
    }
	else if (grade > 150) {
		throw std::invalid_argument( "GradeTooLowException" );
    }
}

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(150) {
	UI::printLine("[Bureaucrat] Default constructor called");
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(150) {
	UI::printLine("[Bureaucrat] Name constructor called");
}

Bureaucrat::Bureaucrat( long int grade ) : _name(""), _grade(grade) {
	UI::printLine("[Bureaucrat] Name constructor called");
	checkGrade(grade);
	//this->_grade = grade;
}

Bureaucrat::Bureaucrat( std::string name, long int grade ) : _name(name), _grade(grade) {
	UI::printLine("[Bureaucrat] Name Grade constructor called");
	checkGrade(grade);
	//this->_grade = grade;
}

Bureaucrat::Bureaucrat( long int grade, std::string name ) : _name(name), _grade(grade) {
	UI::printLine("[Bureaucrat] Grade Name constructor called");
	checkGrade(grade);
	//this->_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name), _grade(other._grade) {
	UI::printLine("[Bureaucrat] Copy constructor called");
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& other ) {
	UI::printLine("[Bureaucrat] Copy assignment operator called");
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	UI::printLine("[Bureaucrat] Destructor called");
}

const std::string&	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

unsigned char		Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}
