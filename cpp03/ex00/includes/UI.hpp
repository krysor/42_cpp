#pragma once
#ifndef __UI_H__
#define __UI_H__

#include <iostream>

#define GREEN "\33[32m"
#define RESET "\33[0m"

class UI {

public:

	static void	printLine( std::string line );

};

#endif