#include "inverse_function.hpp"

unsigned short	*reverse_map(float n)
{
	if (n > 1)
	{
		std::cout << "Value out of range" << std::endl;
		unsigned short	i[2] = {0, 0};
		unsigned short	*j = i;
		return (j);
	}
	unsigned short	x = 0;
	unsigned short	y = 0;
	while (n - (static_cast<float>(1) / 65536) >= 0)
	{
		y++;
		n -= (static_cast<float>(1) / 65536);
	}
	while (n - (static_cast<float>(1) / 4294967296) >= 0)
	{
		x++;
		n -= (static_cast<float>(1) / 4294967296);
	}
	unsigned short	i[2] = {x, y};
	unsigned short	*j = i;
	return (j);
}
