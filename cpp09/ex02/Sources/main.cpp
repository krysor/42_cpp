#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::deque<long>			test;
	std::vector<unsigned long>	v;
	std::deque<unsigned long>	d;
	size_t						size;
	double						time;
	
	if (argc < 3)
		return (printMsg(ERRARGC, EXIT_FAILURE));
	if (fillContainer(test, argv) == FAILURE)
		return (printMsg("Error", EXIT_FAILURE));
	printContainer(test, "Before");
	sort(test.begin(), test.end());
	printContainer(test, "After");
	size = test.size();
	time = timeContainer(v, argv);
	printResult(size, "vector", time);
	time = timeContainer(d, argv);
	printResult(size, "deque", time);
	return (EXIT_SUCCESS);
}
