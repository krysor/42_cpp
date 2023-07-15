#include "Harl.hpp"

void Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complainLevel( std::string label, void (Harl::*complaint)(void) const ) const
{
	std::cout << "[ " + label + " ]" << std::endl;
	if (complaint != NULL)
	{
		(this->*complaint)();
		std::cout << std::endl;
	}
}

void	Harl::complain( std::string level ) const
{
	std::string	levels[]							= 	{"DEBUG", "INFO", "WARNING", "ERROR", ""};
	void 		(Harl::*complaints[])(void) const	=	{&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int			i 									=	0;
	
	while (!levels[i].empty() && levels[i] != level)
		i++;
	switch (i) {
		case 0:
			complainLevel(levels[0], complaints[0]);
		case 1:
			complainLevel(levels[1], complaints[1]);
		case 2:
			complainLevel(levels[2], complaints[2]);
		case 3:
			complainLevel(levels[3], complaints[3]);
			break ;
		default:
			complainLevel("Probably complaining about insignificant problems", NULL);
	}
}