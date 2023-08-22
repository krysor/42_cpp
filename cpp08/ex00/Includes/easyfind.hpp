#pragma once
#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int target)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), target);
	if (iter != container.end())
		return (iter);
	throw std::range_error ("The given target hasn't been found inside the container");
}

#endif
