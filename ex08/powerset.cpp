#include "powerset.hpp"

std::vector<std::vector<int32_t> >	powerset(std::vector<int32_t>	set)
{
	std::vector<std::vector<int32_t> >	powset;
	int									n = 1;
	for (size_t i = 0; i < set.size(); i++)
		n *= 2;
	for (int i = 0; i < n; i++)
	{
		std::vector<int32_t>	pset;
		int						x = i;
		for (size_t j = 0; j < set.size(); j++)
		{
			if (x % 2)
				pset.push_back(set[j]);
			x /= 2;
		}
		powset.push_back(pset);
	}
	return (powset);
}
