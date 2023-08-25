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
		#define SIZE 10000
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
		UI::printLine("result of the shortestSpan: "
					  + std::to_string(span.shortestSpan()));
	}
	catch (std::exception & e) {
		UI::printLine(RED + e.what() + RESET);
	}

	UI::printLine("\n\n");

	UI::printLine(GREEN + "addRange()" + RESET);
	try {
		#define SIZE2 10
		Span				span(SIZE2);
		std::vector<int>	v;

		UI::printLine("Filling a span with SIZE "
					+ std::to_string(SIZE2) + "...");
		for (unsigned int i = 0; i < SIZE2 / 2; i++) {
			int	random = rand() % 100;
			UI::printLine(std::to_string(random));
			span.addNumber(random);
		}

		UI::printLine("Filling a vector v ...");
		for (unsigned int i = 0; i < SIZE2 / 2; i++) {
			int	random = rand() % 100;
			UI::printLine(std::to_string(random));
			v.push_back(random);
		}

		UI::printLine("Filling the rest of the span");
		span.addRange(v.begin(), v.end());

		UI::printLine("Trying to overfill the span");
		span.addRange(v.begin(), v.end());
	}
	catch (std::exception & e) {
		UI::printLine(RED + e.what() + RESET);
	}

	UI::printLine("\n\n");

	return (EXIT_SUCCESS);
}

// int main()
// {
// 	Span sp = Span(5);

// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);

// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;

// 	return 0;
// }