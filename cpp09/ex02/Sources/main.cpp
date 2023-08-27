#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	// char*	ptr;
	
	// std::vector<long>	v;
	// std::deque<long>	d;

	// if (argc < 3)
	// 	return (printMsg(ERRARGC, EXIT_FAILURE));
	
	(void)argv;
	(void)argc;
	
	
	struct timeval t1, t2;
	double elapsedTime;
	
	gettimeofday(&t1, NULL);
	for (unsigned i = 0; i < 10000; i++) {;}
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000000.0;      // sec to ms
    elapsedTime += (t2.tv_usec - t1.tv_usec);   // us to ms
    printf("%f us.\n", elapsedTime);



	// while (*(++argv))
	// {
	// 	long	l = strtol(*argv, &ptr, BASE);
	// 	if (l < 0 || *ptr != '\0')
	// 		return (printMsg("Error", EXIT_FAILURE));
	// 	v.push_back(l);
	// 	d.push_back(l);
	// }


	// if (isSorted(v))
	// 	return (printMsg(ERRSORTED, EXIT_FAILURE));
	return (EXIT_SUCCESS);
}
