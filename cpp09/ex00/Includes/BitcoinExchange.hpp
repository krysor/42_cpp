#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <time.h>

#define	NAMEDATABASE		"data.csv"
#define	FIRSTLINEDATABASE	"date,exchange_rate"

#define	FEBRUARY	1
#define APRIL		3
#define JUNE		5
#define	SEPTEMBER	8
#define NOVEMBER	10

typedef std::map<std::string, double>	dB;

bool	extractDataBase( dB& dataBase );

#endif
