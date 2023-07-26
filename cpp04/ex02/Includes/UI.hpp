#pragma once
#ifndef __UI_H__
#define __UI_H__

#include <iostream>

#define RESET	std::string("\33[0m")
#define RED		std::string("\33[31m")
#define GREEN	std::string("\33[32m")
#define YELLOW	std::string("\33[33m")
#define BLUE	std::string("\33[34m")

class UI {

public:

	static void	printLine( std::string line );

};

#endif