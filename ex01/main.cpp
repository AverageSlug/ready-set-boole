#include "multiplier.cpp"
#include <iostream>

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << multiplier(0, 0) << std::endl;
	}
	else if (argc == 3 && argv[0] && argv[1])
		std::cout << multiplier(atoi(argv[0]), atoi(argv[1])) << std::endl;
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
