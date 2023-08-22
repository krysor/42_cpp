#pragma once
#ifndef __ARRAY_H__
#define __ARRAY_H__

template<class T> 
class Array {

private:

		unsigned int	length;
		T*				ptr;

public:

		Array( void ) {
			length = 0;
			ptr = nullptr;
		}

		Array( unsigned int i ) {
			length = i;
			ptr = nullptr;
			if (length > 0)
				ptr = new T[i];
		}

		Array( const Array& other ) {
			length = other.size();
			ptr = nullptr;
			if (other.size() == 0)
				return ;
			ptr = new T[other.size()];
			for (unsigned int i = 0; i < other.size(); i++) {
				ptr[i] = other[i];
			}
		}

		Array&	operator=( const Array& other ) {
			delete [] ptr;
			ptr = nullptr;
			length = other.size();
			if (other.size() == 0)
				return ;
			ptr = new T[other.size()];
			for (unsigned int i = 0; i < other.size(); i++) {
				ptr[i] = other[i];
			}
		}

		T& operator[](unsigned int index) const {
			if (index >= length)
				throw std::out_of_range ("The given index is outside the array range");
			return (*(ptr + index));
		}

		unsigned int	size( void ) const {
			return (length);
		}
};

#endif