#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

int print_error(std::string msg)
{
	std::cout << msg << "\n";
	return (1);
}

void	replace(std::string &line, std::string strToFind, std::string strToReplace)
{
	int i;

	i = 0;
	while ((i = line.find(strToFind, i)) != -1)
	{
		line.erase(i, strToFind.length());
		line.insert(i, strToReplace);
		i += strToReplace.length();
	}
	
}

int	main(int argc, char **argv)
{
	std::fstream	inputFile;
	std::fstream	outputFile;
	std::string		line;

	if (argc != 4)
		return (print_error("Invalid arguments!\n"));
	inputFile.open(argv[1], std::ios::in);
	if (!inputFile.is_open())
		return (print_error("Failed to open input file!\n"));
	line = argv[1] + (std::string)".replace";
	outputFile.open(line, std::ios::out);
	if (!outputFile.is_open())
		return (print_error("Failed to open output file!\n"));
	while (std::getline(inputFile, line))
	{
		replace(line, argv[2], argv[3]);
		outputFile << line;
		if(!inputFile.eof())
			outputFile << "\n";
	}
	inputFile.close();
	outputFile.close();
	return 0;
}
