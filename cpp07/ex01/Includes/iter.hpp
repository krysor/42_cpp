#pragma once
#ifndef __ITER_H__
#define __ITER_H__

template <typename T>
void iter(T* address, size_t length, T f(T))
{
	for (unsigned int i; i < length, i++) {
		*T = f(*T);
		T++;
	}
}

#endif