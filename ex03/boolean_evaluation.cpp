#include <cstdint>
#include <iostream>
#include <stack>

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
