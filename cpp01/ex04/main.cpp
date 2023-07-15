#include <iostream>
#include <fstream>

int	open_files(char *filename, std::ifstream* input, std::ofstream* output)
{
	input->open(filename, std::ios::in);
	if (*input == NULL)
	{
		std::cout << "Opening of the input file failed" << std::endl;
		return (EXIT_FAILURE);
	}
	output->open((std::string(filename) + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (*output == NULL)
	{
		input->close();
		std::cout << "Opening of the output file failed" << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	replace_in_line(std::string& line, std::string s1, std::string s2)
{
	size_t	i;

	if (s1.empty())
		return ;
	i = line.find(s1, 0);
	while (i != std::string::npos)
	{
		line = line.substr(0, i) + s2 + line.substr(i + s1.length(), line.length());
		i = line.find(s1, 0);
	}
}

int	main(int argc, char *argv[])
{
	std::ifstream	input;
	std::ofstream	output;
	std::string		line;
	
	if (argc != 4)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return (EXIT_FAILURE);
	}
	if (open_files(argv[1], &input, &output) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (std::getline(input, line))
	{
		if (!input.eof())
			line += "\n";
		replace_in_line(line, argv[2], argv[3]);
		output << line;		
	}
	input.close();
	output.close();
	//system("lsof -c ex04");
	return (EXIT_SUCCESS);
}
