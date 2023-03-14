#include <string>
#include "../ex03/boolean_evaluation.cpp"

bool	sat(std::string &formula)
{
	int			j = 0, x = 1, values[26];
	std::string	copy;

	for (int i = 0; i < 26; i++)
		values[i] = -1;
	for (int i = 0; formula[i]; i++)
		if (formula[i] >= 65 && formula[i] <= 90 && values[formula[i] - 65] < 0)
		{
			j++;
			values[formula[i] - 65] = 0;
		}
	for (int i = 0; i < j; i++)
		x *= 2;
	for (int i = 0; i < x; i++)
	{
		int y = i;
		for (int k = 25; k >= 0; k--)
			if (values[k] >= 0)
			{
				values[k] = y % 2;
				y /= 2;
			}
		for (int k = 0; formula[k]; k++)
		{
			if (formula[k] >= 65 && formula[k] <= 90)
				copy.push_back(values[formula[k] - 65] + 48);
			else
				copy.push_back(formula[k]);
		}
		y = eval_formula(copy);
		if (y)
			return (true);
		copy.clear();
	}
	return (false);
}
