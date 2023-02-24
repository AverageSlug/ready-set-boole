#include <cstdint>
#include <iostream>
#include <stack>
#include <vector>

std::vector<int32_t>		eval_set(std::string formula, std::vector<std::vector<int32_t> > sets)
{
	std::stack<std::vector<int32_t> >	s;
	std::vector<int32_t>				t1, t2, t3;
	int									n = 0, values[26];

	for (size_t i = 0; i < sets.size(); i++)
		for (size_t j = 0; j < sets[i].size(); j++)
		{
			size_t	k = 0;
			for (; k < t3.size(); k++)
				if (sets[i][j] == t3[k])
					break ;
			if (k == t3.size())
				t3.push_back(sets[i][j]);
		}
	for (int i = 0; i < 26; i++)
		values[i] = -1;
	for (int i = 0; formula[i]; i++)
		if (formula[i] >= 65 && formula[i] <= 90 && values[formula[i] - 65] < 0)
			values[formula[i] - 65] = n++;
	if (n != sets.size())
	{
		std::cout << "Invalid formula" << std::endl;
		return (std::vector<int32_t>());
	}
	for (uint32_t i = 0; i < formula.size(); i++)
	{
		if (formula[i] >= 65 && formula[i] <= 90)
			s.push(sets[values[formula[i] - 65]]);
		else if (formula[i] == 33)
		{
			if (i < 1)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t1 = s.top();
			s.pop();
			for (int32_t j = 0; j < t3.size(); j++)
			{
				std::vector<int32_t>::iterator	it = t1.begin();
				for (; it != t1.end(); it++)
					if (*it == t3[j])
					{
						t1.erase(it--);
						break ;
					}
				if (it == t1.end())
					t1.push_back(t3[j]);
			}
			s.push(t1);
		}
		else if (formula[i] == 38)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			for (std::vector<int32_t>::iterator it = t1.begin(); it != t1.end(); it++)
			{
				size_t	j = 0;
				for (; j < t2.size(); j++)
					if (*it == t2[j])
						break ;
				if (j == t2.size())
					t1.erase(it--);
			}
			s.push(t1);
		}
		else if (formula[i] == 61)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			for (int j = 0; j < t2.size(); j++)
			{
				std::vector<int32_t>::iterator it = t1.begin();
				for (; it != t1.end(); it++)
					if (*it == t2[j])
					{
						t1.erase(it--);
						break ;
					}
				if (it == t1.end())
					t1.push_back(t2[j]);
			}
			for (int32_t j = 0; j < t3.size(); j++)
			{
				std::vector<int32_t>::iterator	it = t1.begin();
				for (; it != t1.end(); it++)
					if (*it == t3[j])
					{
						t1.erase(it--);
						break ;
					}
				if (it == t1.end())
					t1.push_back(t3[j]);
			}
			s.push(t1);
		}
		else if (formula[i] == 62)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t2 = s.top();
			s.pop();
			t1 = s.top();
			s.pop();
			for (int32_t j = 0; j < t3.size(); j++)
			{
				std::vector<int32_t>::iterator	it = t1.begin();
				for (; it != t1.end(); it++)
					if (*it == t3[j])
					{
						t1.erase(it--);
						break ;
					}
				if (it == t1.end())
					t1.push_back(t3[j]);
			}
			for (int j = 0; j < t2.size(); j++)
			{
				int k = 0;
				for (; k < t1.size(); k++)
					if (t1[k] == t2[j])
						break ;
				if (k == t1.size())
					t1.push_back(t2[j]);
			}
			s.push(t1);
		}
		else if (formula[i] == 94)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			for (int j = 0; j < t2.size(); j++)
			{
				std::vector<int32_t>::iterator it = t1.begin();
				for (; it != t1.end(); it++)
					if (*it == t2[j])
					{
						t1.erase(it--);
						break ;
					}
				if (it == t1.end())
					t1.push_back(t2[j]);
			}
			s.push(t1);
		}
		else if (formula[i] == 124)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (std::vector<int32_t>());
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			for (int j = 0; j < t2.size(); j++)
			{
				int k = 0;
				for (; k < t1.size(); k++)
					if (t1[k] == t2[j])
						break ;
				if (k == t1.size())
					t1.push_back(t2[j]);
			}
			s.push(t1);
		}
		else
		{
			std::cout << "Invalid formula" << std::endl;
			return (std::vector<int32_t>());
		}
		t1.clear();
		t2.clear();
	}
	return (s.top());
}
