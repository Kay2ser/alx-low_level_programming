#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: The binary number as a string
 *
 * Return: The converted unsigned int, or 0 if there is an error
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);

		decimal = decimal * 2 + (b[i] - '0');
	}

	return (decimal);
}

