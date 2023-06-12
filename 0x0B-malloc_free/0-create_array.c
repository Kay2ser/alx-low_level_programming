#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * create_array - create array size:size and assign char c
 *
 * @size: array size
 * @c: char to initialize array with
 *
 * Return: Pointer to array, Otherwise NULL
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;
	return (array);
}
