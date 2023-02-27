#include <cstdint>
#include "../ex00/adder.cpp"

uint32_t	multiplier(uint32_t a, uint32_t b)
{
	uint32_t	sum = 0;
	for (uint32_t i = 0; i < 32; i++)
		for (uint32_t j = 0; j < 32; j++)
			sum = adder(sum, (((b & (1 << j)) << (i >> ((a ^ (1 << i)) << 5))) & ((a & (1 << i)) << (j >> ((b ^ (1 << j)) << 5)))));
	return (sum);
}
