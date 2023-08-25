#include "Span.hpp"

Span::Span( void ) : integers(0), size(0)
{
	UI::printLine("[Span] Default constructor called");
}

Span::Span( unsigned int n ) : integers(0), size(n)
{
	UI::printLine("[Span] Default constructor called");
}

Span::Span( const Span& other ) : integers(other.integers), size(other.size)
{
	UI::printLine("[Span] Copy constructor called");
}

Span&	Span::operator=( const Span& other )
{
	integers = other.integers;
	size = other.size;
	UI::printLine("[Span] Copy assignment operator called");
	return (*this);
}

Span::~Span( void )
{
	UI::printLine("[Span] Destructor called");
}

const char* Span::SpanFull::what() const throw()
{
	return ("The span is full and can't be filled with any extra elements");
}

const char* Span::LongestSpan::what() const throw()
{
	return ("The longest span can't be calculated because span is empty or contains only one element");
}

const char* Span::ShortestSpan::what() const throw()
{
	return ("The shortest span can't be calculated because span is empty or contains only one element");
}

void	Span::addNumber( int nb )
{
	if (integers.size() < size) {
		integers.push_back(nb); 
	}
	else
		throw Span::SpanFull();
}

void	Span::addRange(std::vector<int>::iterator  start,
					   std::vector<int>::iterator end)
{
	long int		rangeWidth;
	unsigned int	nbEmptyIntegers;
	unsigned int	numbersToAdd;

	rangeWidth = end - start;
	if (rangeWidth <= 0)
		return ;
	nbEmptyIntegers = size - integers.size();
	if (rangeWidth > nbEmptyIntegers)
		numbersToAdd = nbEmptyIntegers;
	else
		numbersToAdd = static_cast<unsigned int>(rangeWidth);
	integers.insert(integers.end(), start, start + numbersToAdd);
	if (rangeWidth > nbEmptyIntegers)
		throw Span::SpanFull();
}

unsigned int	Span::shortestSpan( void ) const {
	std::vector<int>	clone;
	long				result;

	if (integers.size() == 0 || integers.size() == 1)
		throw Span::ShortestSpan();
	clone = integers;
	sort(clone.begin(), clone.end());
	for (std::vector<int>::iterator it = clone.begin();
			(it + 1) != clone.end(); it++)
	{
		long	delta = abs(static_cast<long>(*it) - *(it + 1));
		if (delta < result)
			result = delta;
	}
	return (static_cast<unsigned int>(result));
}

unsigned int	Span::longestSpan( void ) const {
	int		max;
	int		min;
	long	delta;
	
	if (integers.size() == 0 || integers.size() == 1)
		throw Span::LongestSpan();
	max = *max_element(integers.begin(), integers.end());
	min = *min_element(integers.begin(), integers.end());
	delta = static_cast<long>(max) - min;
	return (static_cast<unsigned int>(abs(delta)));
}