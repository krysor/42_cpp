#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {


private:

	Contact 	_contacts[8];
	Contact		*_getContacts( void );
	

public:

	PhoneBook( void );
	~PhoneBook( void );
	
	int addContact( void );
	int	search( void );


};

#endif