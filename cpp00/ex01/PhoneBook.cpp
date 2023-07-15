#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	std::cout << "Contructing PhoneBook..." << std::endl;
}

PhoneBook::~PhoneBook( void )
{
	std::cout << "Destructing PhoneBook..." << std::endl;
}

Contact	*PhoneBook::_getContacts(void)
{
	return (this->_contacts);
}
