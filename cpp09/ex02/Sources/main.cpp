#include "PmergeMe.hpp"



int	main(int argc, char *argv[])
{
	std::deque<long>	test;
	
	if (argc < 3)
		return (printMsg(ERRARGC, EXIT_FAILURE));
	if (fillContainer(test, argv) == FAILURE)
		return (printMsg("Error", EXIT_FAILURE));
	printContainer(test, "Before");
	sort(test.begin(), test.end());
	printContainer(test, "After");
	
	// if (isSorted(v))
	// 	return (printMsg(ERRSORTED, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}

/*
	// struct timeval t1, t2;
	// double elapsedTime;
	
	// gettimeofday(&t1, NULL);
	// for (unsigned i = 0; i < 10000; i++) {;}
	// gettimeofday(&t2, NULL);

	// elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000.0;      // sec to ms
    // elapsedTime += (t2.tv_usec - t1.tv_usec);   // us to ms
    // printf("%f us.\n", elapsedTime);
*/