#pragma once
#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "UI.hpp"
#include <cstdint>
#include "Data.hpp"

class Serializer {

private:

	Serializer( void );
	Serializer( const Serializer& other );
	Serializer&	operator=( const Serializer& other );
	~Serializer( void );

public:

	static uintptr_t	serialize(Data* ptr);
	static Data* 		deserialize(uintptr_t raw);
};

#endif