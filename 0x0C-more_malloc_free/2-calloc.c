#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in the array
 * @size: size of each element in the array
 *
 * Return: pointer to the allocated memory, NULL if it fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *tmp;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	tmp = ptr;
	for (i = 0; i < nmemb * size; i++)
		tmp[i] = 0;
	return (ptr);
}
