#include "curve.hpp"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << map(0, 0) << std::endl;
	}
	else if (argc == 3 && argv[0] && argv[1])
		std::cout << map(atoi(argv[0]), atoi(argv[1])) << std::endl;
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
