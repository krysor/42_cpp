#pragma once
#ifndef __ITER_H__
#define __ITER_H__

#include <stddef.h>

template <typename T>
void dummy(T& input)
{
	input++;
}

template <typename T>
void iter(T* address, size_t length, void f(T&))
{
	for (size_t i = 0; i < length; i++) {
		f(*address);
		address++;
	}
}

#endif