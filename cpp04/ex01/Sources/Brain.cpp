#include "Brain.hpp"
#include "UI.hpp"

Brain::Brain( void )
{
	UI::printLine("[Brain] Default constructor called");
}

Brain::Brain( std::string ideas[IDEASSIZE] )
{
	UI::printLine("[Brain] Name constructor called");
	setIdeas(ideas);
}

Brain::Brain( const Brain& other )
{
	UI::printLine("[Brain] Copy constructor called");
	operator=(other);
}

Brain&	Brain::operator=( const Brain& other )
{
	UI::printLine("[Brain] Copy assignment operator called");
	setIdeas(other._ideas);
	return (*this);
}

Brain::~Brain( void )
{
	UI::printLine("[Brain] Destructor called");
}

const std::string*	Brain::getIdeas( void ) const
{
	return (this->_ideas);
}

void	Brain::setIdeas( const std::string ideas[IDEASSIZE] )
{
	for (unsigned int i = 0; i < IDEASSIZE; i++) {
		this->_ideas[i] = ideas[i];
	}
}
