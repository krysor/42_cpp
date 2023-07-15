#include "PhoneBook.hpp"

static void	displayFirstRow(void)
{
	std::string	columnNames[] = {"index", "first name", "last name", "nickname"};

	int	i = -1;
	while (++i < 4)
		std::cout << "|" << std::setw(10) << columnNames[i];
	std::cout << "|" << std::endl;
}

static void	displayContacts(Contact *contacts)
{
	std::string (Contact::*getters[])() const = {&Contact::getFirstName, &Contact::getLastName, &Contact::getNickname};
	
	displayFirstRow();
	int i = -1;
	while (++i < 8)
	{
		std::cout << "|" << std::setw(10) << i;
		int	j = -1;
		while (++j < 3)
		{
			std::cout << "|";	
			std::string	str = (contacts[i].*getters[j])();
			if (str.length() > 10)
				std::cout << str.substr(0, 9) << ".";
			else
				std::cout << std::setw(10) << str;
		}
		std::cout << "|" << std::endl;
	}
}

static int	getIndexContact(void)
{
	std::string	str;

	while (1)
	{
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "\nEOF encounterd or an error occurred..." << std::endl;
			return (-1);
		}
		else if (str.empty())
			std::cout << "Enter the index of the contact you want to display:" << std::endl;
		else if (!std::all_of(str.begin(), str.end(), ::isdigit))
			std::cout << "Oeps... non numeric or negative input found. Try again" << std::endl;
		else if (str.length() > 1 || std::atoi(str.c_str()) > 7)
			std::cout << "Oeps... the given input must be smaller than 8" << std::endl;
		else
			break ;
		std::getline(std::cin, str);
	}
	return (std::atoi(str.c_str()));
}

int	PhoneBook::search(void)
{
	Contact 	*contacts;
	int			index;
	std::string	rowNames[] 						= {"First Name", "Last name", "Nickname", "Phone number", "Darkest secret"};
	std::string (Contact::*getters[])() const	= {&Contact::getFirstName, &Contact::getLastName, &Contact::getNickname, &Contact::getPhoneNumber, &Contact::getDarkestSecret};
	
	contacts = _getContacts();
	displayContacts(contacts);
	index = getIndexContact();
	if (index < 0)
		return (EXIT_FAILURE);
	if (contacts[index].getFirstName().empty())
	{
		std::cout << "There is no contact at this index yet :(" << std::endl;
		return (EXIT_SUCCESS);
	}
	std::cout << "This is the contact at index " << index << " :" << std::endl;
	int i = -1;
	while (++i < 5)
		std::cout << std::setw(14) << std::left << rowNames[i] << " : " << (contacts[index].*getters[i])() << std::endl;
	return (EXIT_SUCCESS);
}
