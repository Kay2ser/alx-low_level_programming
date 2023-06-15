#include <stdlib.h>
#include "main.h"

/**
 * array_range - creates an array of integers
 * @min: minimum value
 * @max: maximum value
 *
 * Return: pointer to the newly created array
 *         NULL if malloc fails or min > max
 */
int *array_range(int min, int max)
{
	int *arr;
	int size, i;

	if (min > max)
		return (NULL);
	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = min + i;
	return (arr);
}

