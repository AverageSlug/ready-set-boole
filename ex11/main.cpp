#include "inverse_function.hpp"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << reverse_map(0)[0] << "|" << reverse_map(0)[1] << std::endl;
	}
	else if (argc == 2 && argv[0])
		std::cout << reverse_map(atof(argv[0]))[0] << "|" << reverse_map(atof(argv[0]))[1] << std::endl;
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
