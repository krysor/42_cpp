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

class	Date {

private:

	struct tm	date;

public:

	Date( void );
	Date( struct tm& date );
	Date( const Date& other );
	~Date( void );
	Date& operator=( const Date& other );

	bool	operator==( const Date& other ) const;
	bool	operator >( const Date& other ) const;
	bool	operator>=( const Date& other ) const;
	bool	operator <( const Date& other ) const;
	bool	operator<=( const Date& other ) const;

	const Date&	operator--( void );

	struct tm& getDate( void );
};

typedef std::map<Date, double>	data;

bool	extractData( data& dataBase, const char* nameFile );
bool	processInputFile( const char* nameFile, data& dataBase );

#endif
