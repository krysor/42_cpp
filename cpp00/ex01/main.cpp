#include "PhoneBook.hpp"

int	main(void)
{
	std::string	str;
	PhoneBook	phoneBook;

	system("clear");
	std::cout << "Welcome to the Phonebook program. Try ADD, SEARCH or EXIT" << std::endl;
	std::getline(std::cin, str);
	while (str != "EXIT")
	{
		if (std::cin.eof() || std::cin.fail())
		{
			std::cout << "\nEOF encounterd or an error occurred..." << std::endl;
			return (EXIT_FAILURE);
		}
		if (str == "ADD")
		{
			if (phoneBook.addContact() == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (str == "SEARCH")
		{
			if (phoneBook.search() == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else
			std::cout << "Wrong input command." << std::endl;
		std::cout << "Try ADD, SEARCH or EXIT" << std::endl;
		std::getline(std::cin, str);
	}
	std::cout << "Ending the PhoneBook program..." << std::endl;
	return (EXIT_SUCCESS);
}
