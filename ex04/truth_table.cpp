#include <string>
#include "../ex03/boolean_evaluation.cpp"

void	print_truth_table(std::string formula)
{
	int			j = 0, k = 0, values[26];
	std::string	copy;
	for (int i = 0; i < 26; i++)
		values[i] = -1;
	for (int i = 0; formula[i]; i++)
		if (formula[i] >= 65 && formula[i] <= 90 && values[formula[i] - 65] < 0)
		{
			j++;
			values[formula[i] - 65] = 0;
		}
	k = j - 1;
	for (int i = 0; i < (2^j); i++)
	{
		for (int l = 0; l < 26; l++)
			if (values[l] >= 0)
				values[l] = (i / (2^k)) % 2;
	}
}
