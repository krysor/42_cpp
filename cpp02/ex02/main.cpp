#include "Fixed.hpp"

// int main( void ) {

// 	Fixed a(42.42f);
// 	Fixed b(42.41f);
// 	Fixed c(a);

// 	std::cout << "greater than" << std::endl;
// 	std::cout << (a > b) << std::endl; // true
// 	std::cout << (b > c) << std::endl; // false
// 	std::cout << (c > a) << std::endl; // false

// 	std::cout << "smaller than" << std::endl;
// 	std::cout << (a < b) << std::endl; // false
// 	std::cout << (b < c) << std::endl; // true
// 	std::cout << (c < a) << std::endl; // false

// 	std::cout << "greater or equal" << std::endl;
// 	std::cout << (a >= b) << std::endl; // true
// 	std::cout << (a >= c) << std::endl; // true
// 	std::cout << (b >= c) << std::endl; // false

// 	std::cout << "smaller or equal" << std::endl;
// 	std::cout << (a <= b) << std::endl; // false
// 	std::cout << (a <= c) << std::endl; // true
// 	std::cout << (b <= c) << std::endl; // true

// 	std::cout << "equal" << std::endl;
// 	std::cout << (a == b) << std::endl; // false
// 	std::cout << (a == c) << std::endl; // true
// 	std::cout << (b == c) << std::endl; // false

// 	std::cout << "not equal" << std::endl;
// 	std::cout << (a != b) << std::endl; // true
// 	std::cout << (a != c) << std::endl; // false
// 	std::cout << (b != c) << std::endl; // true

// 	std::cout << (a + b) << std::endl;
// 	std::cout << (b + a) << std::endl;

// 	std::cout << (a - b) << std::endl;
// 	std::cout << (b - a) << std::endl;

// 	std::cout << (a * b) << std::endl;
// 	std::cout << (b * a) << std::endl;

// 	std::cout << (a / b) << std::endl;
// 	std::cout << (b / a) << std::endl;

// 	std::cout << "pre increment" << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << "pre decrement" << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << --a << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << "post increment" << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << "post decrement" << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a-- << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << "min" << std::endl;
// 	std::cout << Fixed::min(a, b) << std::endl;

// 	std::cout << "max" << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;

// 	return 0;
// }


int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
