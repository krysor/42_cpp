#pragma once
#ifndef __UI_H__
#define __UI_H__

#include <iostream>

#define RESET	"\33[0m"
#define RED		"\33[31m"
#define GREEN	"\33[32m"
#define YELLOW	"\33[33m"
#define BLUE	"\33[34m"

class UI {

public:

	static void	printLine( std::string line );

};

#endif