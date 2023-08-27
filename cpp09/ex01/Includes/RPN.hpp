#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

#define ERRARGC			"Error: provide exactly one argument\n" 
#define ERRSTACKSIZE	"Error: not enough elements on the stack to perform an operation.\n"
#define ERRZERO 		"Error: division by zero.\n"
#define ERRINPUT 		"Error: incorrect input.\n"
#define ERREND 			"Error: at the end of the program there should be exactly one element left on the stack.\n"

bool	calculate( char c, std::stack<long>& stack );



#endif
