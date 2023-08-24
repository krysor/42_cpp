#include "Span.hpp"

int	main( void )
{	
	srand(time(NULL));
	
	UI::printLine("\n\n");

	UI::printLine(GREEN + "addNumber()" + RESET);
	try {
		Span	span(1);

		UI::printLine("trying to add one element");
		span.addNumber(0);
		UI::printLine("trying to add a second element");
		span.addNumber(0);
	}
	catch (std::exception & e) {
		UI::printLine(RED + e.what() + RESET);
	}

	UI::printLine("\n\n");

	UI::printLine(GREEN + "shortest- / longestSpan" + RESET);
	{
		#define SIZE 10
		Span	span(SIZE);

		UI::printLine("Filling the span...");
		for (unsigned int i = 0; i < SIZE; i++) {
			int	random = rand() % 100;
			UI::printLine(std::to_string(random));
			span.addNumber(random);
		}

		UI::printLine("result of the longestSpan: "
					  + std::to_string(span.longestSpan()));
		UI::printLine("result of the shortestSpan: "
					  + std::to_string(span.shortestSpan()));
	}

	UI::printLine("\n\n");

	UI::printLine(GREEN + "longestSpan with empty span" + RESET);
	try {
		Span	span;

		UI::printLine("result of the longestSpan: "
					  + std::to_string(span.longestSpan()));
	}
	catch (std::exception & e) {
		UI::printLine(RED + e.what() + RESET);
	}

	UI::printLine("\n\n");

	UI::printLine(GREEN + "shortestSpan with single element span" + RESET);
	try {
		Span	span(1);
		
		span.addNumber(0);
		UI::printLine("result of the longestSpan: "
					  + std::to_string(span.longestSpan()));
	}
	catch (std::exception & e) {
		UI::printLine(RED + e.what() + RESET);
	}

	UI::printLine("\n\n");

	return (EXIT_SUCCESS);
}
