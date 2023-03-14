#include "adder.hpp"

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
