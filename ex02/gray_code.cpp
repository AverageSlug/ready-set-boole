#include <cstdint>

uint32_t	gray_code(uint32_t n)
{
	return ((n >> 1) ^ n);
}
