#include "Point.hpp"

#include <iomanip>

void	print_point(Point point)
{
	std::cout << "("
			  << std::setw(10) << std::left
			  << point.getX()
			  << ","
			  << std::setw(10) << std::left
			  << point.getY()
			  << ") ";
}

void	print_triangle(Point a, Point b, Point c)
{
	std::cout << "the triangle with vertexes";
	std::cout << std::endl << "	a ";
	print_point(a);
	std::cout << std::endl << "	b ";
	print_point(b);
	std::cout << std::endl << "	c ";
	print_point(c);
	std::cout << std::endl;
}

int main( void ) {

	//the triangle used for testing:
	// Point	a;
	// Point	b(1,1);
	// Point	c(1,0);

	//the triangle
	Point	a;
	Point	b(1,1);
	Point	c(1,0);

	print_triangle(a, b, c);

	//vertexes
	Point	d = a;			//out
	Point	e = b;			//out
	Point	f = c;			//out

	//edges
	Point	g(1, 0.5);		//out
	Point	h(0.5, 0);		//out
	Point	i(0.5, 0.5);	//out

	//clearly out
	Point	j(0.5, -0.25);	//out
	Point	k(0.25, 0.5);	//out
	Point	l(0.01, 0.1);	//out

	//clearly in
	Point	m(0.5, 0.25);	//in
	Point	n(0.1, 0.01);	//in

	Point	array[] = {d, e, f, g, h, i, j, k, l, m, n};
	int 	index = -1;
	while (++index < sizeof(array)/sizeof(Point))
	{
		std::cout << "the point ";
		print_point(array[index]);
		
		std::string str;
		if (bsp(a, b, c, array[index]))
			str = "inside";
		else
			str = "outside";

		std::cout << "is " + str + " the triangle" << std::endl;
	}

	return (EXIT_SUCCESS);
}
