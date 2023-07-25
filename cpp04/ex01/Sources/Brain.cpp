#include "Brain.hpp"
#include "UI.hpp"

Brain::Brain( void )
{
	UI::printLine("[Brain] Default constructor called");
}

Brain::Brain( std::string ideas[100] ) : _ideas(ideas)
{
	UI::printLine("[Brain] Name constructor called");
}

Brain::Brain( const Brain& other ) : _ideas(other._ideas)
{
	UI::printLine("[Brain] Copy constructor called");
}

Brain&	Brain::operator=( const Brain& other )
{
	UI::printLine("[Brain] Copy assignment operator called");
	this->_ideas = other.getIdeas();
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

void	Brain::setIdeas( const std::string ideas[100] )
{
	this->_ideas = ideas;
}
