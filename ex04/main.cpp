#include "truth_table.cpp"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string		test("A");
		print_truth_table(test);
	}
	else if (argc == 2 && argv[0])
	{
		std::string		test(argv[0]);
		print_truth_table(test);
	}
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
