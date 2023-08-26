#pragma once
#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

#define	NAMEDATABASE "data.csv"

bool	extractDataBase( std::map<std::string, float>& dataBase );
bool	parseLine(std::string& line,
				  std::map<std::string, float>& dataBase);

#endif
