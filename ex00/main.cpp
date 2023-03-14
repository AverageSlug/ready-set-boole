#include "adder.hpp"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "0 + 0 = " << adder(0, 0) << std::endl;
		std::cout << "1 + 0 = " << adder(1, 0) << std::endl;
		std::cout << "0 + 1 = " << adder(0, 1) << std::endl;
		std::cout << "1 + 1 = " << adder(1, 1) << std::endl;
		std::cout << "10 + 10 = " << adder(10, 10) << std::endl;
		std::cout << "19 + 42 = " << adder(19, 42) << std::endl;
		std::cout << "4294967295 + 0 = " << adder(4294967295, 0) << std::endl;
		std::cout << "4294967295 + 1 = " << adder(4294967295, 1) << std::endl;
		std::cout << "1 + 4294967295 = " << adder(1, 4294967295) << std::endl;
		std::cout << "0 + 1 + 2 = " << adder(adder(0, 1), 2) << std::endl;
		std::cout << "69 + 420 + 1337 = " << adder(adder(69, 420), 1337) << std::endl;
		std::cout << "4294967295 + 666 + 999 = " << adder(adder(4294967295, 666), 999) << std::endl;
	}
	else if (argc == 3 && argv[0] && argv[1])
		std::cout << adder(atoi(argv[0]), atoi(argv[1])) << std::endl;
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
