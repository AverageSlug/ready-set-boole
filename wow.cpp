#include <cstdint>
#include <iostream>
#include <stack>
#include <cstring>
#include <string>

uint32_t	adder(uint32_t a, uint32_t b)
{
	for (int i = 0; i <= 32; i++)
	{
		uint32_t	t = a;
		a = a ^ b;
		b = (t & b) << 1;
	}
	return (a);
}

uint32_t	multiplier(uint32_t a, uint32_t b)
{
	uint32_t	sum = 0;
	for (uint32_t i = 0; i < 32; i++)
	{
		for (uint32_t j = 0; j < 32; j++)
		{
			sum = adder(sum, (((b & (1 << j)) << (i >> ((a ^ (1 << i)) << 5))) & ((a & (1 << i)) << (j >> ((b ^ (1 << j)) << 5)))));
		}
	}
	return (sum);
}

uint32_t	gray_code(uint32_t n)
{
	return ((n >> 1) ^ n);
}

bool		eval_formula(std::string formula)
{
	std::stack<bool>	s;
	bool				t1;
	bool				t2;
	for (uint32_t i = 0; i < formula.size(); i++)
	{
		if (formula[i] == 49)
			s.push(true);
		else if (formula[i] == 48)
			s.push(false);
		else if (formula[i] == 33)
		{
			if (i < 1)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			s.push(!t1);
		}
		else if (formula[i] == 38)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			s.push(t1 & t2);
		}
		else if (formula[i] == 61)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			s.push(t1 == t2);
		}
		else if (formula[i] == 62)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			s.push(!(t2 > t1));
		}
		else if (formula[i] == 94)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			s.push(t1 ^ t2);
		}
		else if (formula[i] == 124)
		{
			if (i < 2)
			{
				std::cout << "Invalid formula" << std::endl;
				return (0);
			}
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			s.push(t1 | t2);
		}
		else
		{
			std::cout << "Invalid formula" << std::endl;
			return (0);
		}
	}
	return (s.top());
}

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

void	sat()
{}

int	main()
{
	std::cout << eval_formula("1011||=") << std::endl;
}