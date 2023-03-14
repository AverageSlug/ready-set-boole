#include "gray_code.cpp"
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << gray_code(0) << std::endl;
	}
	else if (argc == 2 && argv[0])
		std::cout << gray_code(atoi(argv[0])) << std::endl;
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
