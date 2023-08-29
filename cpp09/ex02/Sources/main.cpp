#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::deque<long>					test;
	size_t								size;
	double								time;
	std::vector< std::vector<long> >	v(argc - 1);
	std::deque < std::deque <long> >	d(argc - 1);

	if (argc < 3)
		return (printMsg(ERRARGC, EXIT_FAILURE));
	if (fillContainer(test, argv) == FAILURE)
		return (printMsg("Error", EXIT_FAILURE));
	printContainer(test, "Before");
	sort(test.begin(), test.end());
	if (containsDuplicates(test))
		return (printMsg(ERRDUPL, EXIT_FAILURE));
	//printContainer(test, "After");
	size = test.size();
	time = timeContainer(v, argv);
	//printResult(size, "vector", time);
	//time = timeContainer(d, argv);
	//printResult(size, "deque", time);
	return (EXIT_SUCCESS);
}

/*
int	main(int argc, char *argv[])
{
	std::deque <long>	test;
	std::vector<long>	v;
	std::deque <long>	d;
	size_t				size;
	double				time;
	
	if (argc < 3)
		return (printMsg(ERRARGC, EXIT_FAILURE));
	if (fillContainer(test, argv) == FAILURE)
		return (printMsg("Error", EXIT_FAILURE));
	//printContainer(test, "Before");
	sort(test.begin(), test.end());
	if (containsDuplicates(test))
		return (printMsg(ERRDUPL, EXIT_FAILURE));
	//printContainer(test, "After");
	size = test.size();
	time = timeContainer(v, argv);
	//printResult(size, "vector", time);
	//time = timeContainer(d, argv);
	//printResult(size, "deque", time);
	return (EXIT_SUCCESS);
}*/
