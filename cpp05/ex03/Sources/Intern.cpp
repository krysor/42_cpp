#include "Intern.hpp"

Intern::Intern( void ) {
	UI::printLine("[Intern] Default constructor called");
}


Intern::Intern( const Intern& other ) {
	(void)other;
	UI::printLine("[Intern] Copy constructor called");
}

Intern&	Intern::operator=( const Intern& other ) {
	(void)other;
	UI::printLine("[Intern] Copy assignment operator called");
	return (*this);
}

Intern::~Intern( void ) {
	UI::printLine("[Intern] Destructor called");
}

Form*	Intern::makeForm( std::string nameForm, std::string targetForm )
{
	unsigned int	i;
	std::string		names[] = {"ShrubberyCreationForm",
							   "RobotomyRequestForm",
							   "PresidentialPardonForm"};

	for (i = 0; i < sizeof(names)/sizeof(names[0]) ; i++) {
		if (names[i] == nameForm)
			break ;
	}
	UI::printLine("Intern creates " + names[i]);
	switch (i) {
		case 0:
			return (new ShrubberyCreationForm(targetForm));
		case 1:
			return (new RobotomyRequestForm(targetForm));
		case 2:
			return (new PresidentialPardonForm(targetForm));
		default: {
			UI::printLine("The form name " + nameForm + " doesn't exist");
			return (nullptr);
		}	
	}
}
