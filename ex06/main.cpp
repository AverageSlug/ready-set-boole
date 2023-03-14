#include "conjunctive_normal_form.cpp"

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string		test("A");
		std::cout << conjunctive_normal_form(test) << std::endl;
	}
	else if (argc == 2 && argv[0])
	{
		std::string		test(argv[0]);
		std::cout << conjunctive_normal_form(test) << std::endl;
	}
	else
		std::cout << "Invalid input" << std::endl;
	return (0);
}
