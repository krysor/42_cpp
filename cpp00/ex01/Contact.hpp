#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>

class Contact {


private:

	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;


public:

	Contact( void );
	~Contact( void );

	std::string	getFirstName( void ) const;
	std::string	getLastName( void ) const;
	std::string	getNickname( void ) const;
	std::string getPhoneNumber( void ) const;
	std::string getDarkestSecret( void ) const;
	
	void 		setFirstName( std::string firstName );
	void 		setLastName( std::string lastName );
	void 		setNickname( std::string nickname );
	void 		setPhoneNumber( std::string phoneNumber );
	void 		setDarkestSecret( std::string darkestSecret );


};

#endif