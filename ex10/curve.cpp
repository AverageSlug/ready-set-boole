#include <iostream>

float	map(unsigned short x, unsigned short y)
{
	if (x > 65535 || y > 65535)
	{
		std::cout << "Value out of range" << std::endl;
		return (0);
	}
	float	ret = 0;
	for (int i = 0; i < x; i++)
		ret += (static_cast<float>(1) / 4294967296);
	for (int i = 0; i < y; i++)
		ret += (static_cast<float>(1) / 65536);
	return (ret);
}

float	map(unsigned short coords[2])
{
	if (x > 65535 || y > 65535)
	{
		std::cout << "Value out of range" << std::endl;
		return (0);
	}
	float	ret = 0;
	for (int i = 0; i < coords[0]; i++)
		ret += (static_cast<float>(1) / 4294967296);
	for (int i = 0; i < coords[1]; i++)
		ret += (static_cast<float>(1) / 65536);
	return (ret);
}
