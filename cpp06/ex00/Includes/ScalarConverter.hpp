#pragma once
#ifndef __SCALARCONVERTER_H__
#define __SCALARCONVERTER_H__

#include <string>
#include "UI.hpp"

class ScalarConverter {


private:

	ScalarConverter( void );
	ScalarConverter( const ScalarConverter& other );
	ScalarConverter&	operator=( const ScalarConverter& other );
	~ScalarConverter( void );

public:

	static void	convert( char *str );
};

#endif