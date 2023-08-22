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
void iter(T* address, unsigned int length, void f(T&))
{
	if (address == nullptr)
		return ;
	for (unsigned int i = 0; i < length; i++) {
		f(*(address + i));
	}
}

#endif