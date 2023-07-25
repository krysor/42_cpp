#pragma once
#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>

class Brain {


private:

	std::string	_ideas[100];


public:

	Brain( void );
	Brain( std::string ideas[100] );
	Brain( const Brain& other );
	Brain&	operator=( const Brain& other );
	~Brain( void );

	const std::string*	getIdeas( void ) const;
	void				setIdeas( const std::string ideas[100] );
};

#endif