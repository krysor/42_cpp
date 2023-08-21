#pragma once
#ifndef __ARRAY_H__
#define __ARRAY_H__

template<class T> 
class Array {

private:

		T*				ptr;
		unsigned int	length;

public:

		Array( void ) {
			ptr = nullptr;
			length = 0;
		}

		Array( unsigned int i ) {
			length = i;
			if (length > 0)
				ptr = new T[i];
			else
				ptr = nullptr;
		}

		Array( const Array& other ) {
			length = other.size();
			if (other.size() == 0) {
				ptr = nullptr;
				return ;
			}	
			ptr = new T[other.size()];
			for (unsigned int i = 0; i < other.size(); i++) {
				ptr[i] = other[i];
			}
		}

		Array&	operator=( const Array& other ) {
			delete [] ptr;
			length = other.size();
			if (other.size() == 0) {
				ptr = nullptr;
				return ;
			}	
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