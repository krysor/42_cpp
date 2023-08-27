#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <time.h>

#define	NAMEDATABASE		"data.csv"
#define	FIRSTLINEDATABASE	"date,exchange_rate"
#define	FIRSTLINEINPUTFILE	"date | value"
#define	SEPARATORINPUTFILE	" | "

#define	FEBRUARY	1
#define APRIL		3
#define JUNE		5
#define	SEPTEMBER	8
#define NOVEMBER	10

class	CustomTime {

private:

	struct tm	time;

public:

	CustomTime( void );
	CustomTime( struct tm& time );
	CustomTime( const CustomTime& other );
	~CustomTime( void );
	CustomTime& operator=( const CustomTime& other );

	bool	operator==( const CustomTime& other ) const;
	bool	operator >( const CustomTime& other ) const;
	bool	operator>=( const CustomTime& other ) const;
	bool	operator <( const CustomTime& other ) const;
	bool	operator<=( const CustomTime& other ) const;

	const CustomTime&	operator--( void );

	struct tm& getTime( void );
};

typedef std::map<CustomTime, double>	data;

bool	extractData( data& dataBase, const char* nameFile );
bool	processInputFile( const char* nameFile, data& dataBase );

#endif
