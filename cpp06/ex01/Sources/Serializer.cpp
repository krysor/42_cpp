#include "Serializer.hpp"

Serializer::Serializer( void )
{
	UI::printLine("[Serializer] Default constructor called");
}

Serializer::Serializer( const Serializer& other )
{
	(void)other;
	UI::printLine("[Serializer] Copy constructor called");
}

Serializer&	Serializer::operator=( const Serializer& other )
{
	(void)other;
	UI::printLine("[Serializer] Copy assignment operator called");
	return (*this);
}

Serializer::~Serializer( void )
{
	UI::printLine("[Serializer] Destructor called");
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
