#include "PhoneBook.hpp"

static std::string	getFieldValue(std::string fieldName, void (Contact::*setter)(std::string))
{
	std::string	str;
	while (str.empty())
	{
		std::cout << "Enter " + fieldName << std::endl;
		std::getline(std::cin, str);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "\nEOF encounterd or an error occurred..." << std::endl;
			str.clear();
			return (str);
		}
		if ((setter == &Contact::setFirstName || setter == &Contact::setLastName)
			&& !std::all_of(str.begin(), str.end(), ::isalpha))
			std::cout << "The names can only contain alphabetic letters" << std::endl;
		else if (setter == &Contact::setPhoneNumber && !std::all_of(str.begin(), str.end(), ::isdigit))
			std::cout << "The phone number can only contain digits" << std::endl;
		else
			continue ;
		str.clear();
	}
	return (str);
}

int PhoneBook::addContact(void)
{
	static unsigned int	i 									= 0;
	std::string			fieldNames[]						= {"first name", "last name", "nickname", "phone number", "darkest secret"};
	void 				(Contact::*setters[])(std::string)	= {&Contact::setFirstName, &Contact::setLastName, &Contact::setNickname, &Contact::setPhoneNumber, &Contact::setDarkestSecret};

	std::cout << "Adding a new contact..." << std::endl;
	Contact *contact_pnt = &_getContacts()[i++ % 8];
	int j = -1;
	while (++j < 5)
	{
		std::string FieldValue = getFieldValue(fieldNames[j], setters[j]);
		if (FieldValue == "")
			return (EXIT_FAILURE);
		(*contact_pnt.*setters[j])(FieldValue);
	}
	std::cout << "A new contact has been added succesfully :)" << std::endl;
	return (EXIT_SUCCESS);
}
