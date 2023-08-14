#include "Bureaucrat.hpp"
#include "UI.hpp"

void	Bureaucrat::checkGrade(long int grade) {
	if (grade < GRADEMAX) {
		throw Bureaucrat::GradeTooHighException();
    }
	else if (grade > GRADEMIN) {
		throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat( void ) : _name(""), _grade(GRADEMIN) {
	UI::printLine("[Bureaucrat] Default constructor called");
}

Bureaucrat::Bureaucrat( std::string name ) : _name(name), _grade(GRADEMIN) {
	UI::printLine("[Bureaucrat] Name constructor called");
}

Bureaucrat::Bureaucrat( long int grade ) : _name(""), _grade(grade) {
	UI::printLine("[Bureaucrat] Grade constructor called");
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

Bureaucrat::~Bureaucrat( void ) throw()
{
	UI::printLine("[Bureaucrat] Destructor called");
}

const std::string&	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high (grade < 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low (grade > 150)");
}

const Bureaucrat&	Bureaucrat::operator++( void )
{
	checkGrade(this->_grade);
	checkGrade(this->_grade - 1);
	this->_grade--;
	return (*this);
}

const Bureaucrat	Bureaucrat::operator++(int)
{
	checkGrade(this->_grade);
	checkGrade(this->_grade - 1);
	Bureaucrat	bureaucrat = Bureaucrat(*this);
	this->_grade--;
	return (bureaucrat);
}

const Bureaucrat&	Bureaucrat::operator--( void )
{
	checkGrade(this->_grade);
	checkGrade(this->_grade + 1);
	this->_grade++;
	return (*this);
}

const Bureaucrat		Bureaucrat::operator--( int )
{
	checkGrade(this->_grade);
	checkGrade(this->_grade + 1);
	Bureaucrat	bureaucrat = Bureaucrat(*this);
	this->_grade++;
	return (bureaucrat);
}

void Bureaucrat::signForm(Form& form)
{
	bool	alreadySigned;
	
	alreadySigned = form.getSigned();
	form.beSigned(*this);
	if (!alreadySigned && form.getSigned() == true) {
		UI::printLine(this->getName()
					  + " signed "
					  + form.getName());
	}
	else {
		UI::printLine(this->getName()
				+ " couldn't sign "
				+ form.getName()
				+ " because "
				+ (alreadySigned ?
					"it has already been signed"
					: "the bureaucrat's level is too low"));
	}
}

std::ostream&	operator<<( std::ostream& os,
							const Bureaucrat& bureaucrat )
{
	os << bureaucrat.getName() + ", bureaucrat grade "
		  + std::to_string(bureaucrat.getGrade()) + ".";
	return (os);
}
